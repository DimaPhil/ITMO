#include "executor.h"
#include <logger.h>

#include <cassert>
#include <iostream>
#include <iostream>

#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/signalfd.h>

Executor::Executor() :
    MAX_EVENTS(1024),
    events(MAX_EVENTS) {
    globalfd = epoll_create1(0);

    sigset_t mask;
    int r = sigemptyset(&mask);
    if (r == -1) {
        logger.error("An error occurred in Executor::Executor() in sigemptyset(): " + std::string(strerror(errno)));
        throw std::runtime_error("Executor::Executor(), sigemptyset() failed");
    }
    r = sigaddset(&mask, SIGINT);
    if (r == -1) {
        logger.error("An error occurred in Executor::Executor() in sigaddset(SIGINT): " + std::string(strerror(errno)));
        throw std::runtime_error("Executor::Executor(), sigaddset(SIGINT) failed");
    }
    r = sigaddset(&mask, SIGTERM);
    if (r == -1) {
        logger.error("An error occurred in Executor::Executor() in sigaddset(SIGTERM): " + std::string(strerror(errno)));
        throw std::runtime_error("Executor::Executor(), sigaddset(SIGTERM) failed");
    }

    if (sigprocmask(SIG_BLOCK, &mask, 0) == -1) {
        logger.error("An error occurred in Executor::Executor() while trying to set new block signals (sigprocmask)" + std::string(strerror(errno)));
        throw std::runtime_error("Executor::Executor(), sigprocmask(SIG_BLOCK) failed");
    }

    sigfd = signalfd(-1, &mask, 0);
    if (sigfd == -1) {
        logger.error("An error occurred in Executor::Executor() in signalfd()" + std::string(strerror(errno)));
        throw std::runtime_error("Executor::Executor(), signalfd() failed");
    }
    epoll_event event;
    memset(&event, 0, sizeof event);
    event.data.fd = sigfd;
    event.events = EPOLLIN;
    r = epoll_ctl(globalfd, EPOLL_CTL_ADD, sigfd, &event);
    if (r == -1) {
        logger.error("An error occurred in Executor::Executor() in epoll_ctl()" + std::string(strerror(errno)));
        throw std::runtime_error("Executor::Executor(), epoll_ctl() failed");
    }
}

int Executor::setHandler(int fd, EventHandler handler, uint32_t flags) {
    epoll_event event;
    memset(&event, 0, sizeof event);
    event.data.fd = fd;
    event.events = flags;
    if (handlers.find(fd) != handlers.end()) {
        int exitCode = epoll_ctl(globalfd, EPOLL_CTL_MOD, fd, &event);
        if (exitCode == -1) {
            logger.error("An error occurred in Executor::setHandler() in epoll_ctl(EPOLL_CTL_MOD)" + std::string(strerror(errno)));
            throw std::runtime_error("Executor::setHandler(), epoll_ctl(EPOLL_CTL_MOD) failed");
        }
        handlers[fd] = handler;
        return exitCode;
    }
    int exitCode = epoll_ctl(globalfd, EPOLL_CTL_ADD, fd, &event);
    if (exitCode == 0) {
        handlers[fd] = handler;
    } else {
        logger.error("An error occurred in Executor::setHandler() in epoll_ctl(EPOLL_CTL_ADD)" + std::string(strerror(errno)));
        throw std::runtime_error("Executor::setHandler(), epoll_ctl(EPOLL_CTL_ADD) failed");
    }
    return exitCode;
}

void Executor::changeFlags(int fd, uint32_t flags) {
    epoll_event event;
    memset(&event, 0, sizeof event);
    event.events = flags;
    event.data.fd = fd;
    int r = epoll_ctl(globalfd, EPOLL_CTL_MOD, fd, &event);
    if (r == -1) {
        logger.error("An error occurred in Executor::changeFlags() in epoll_ctl(EPOLL_CTL_MOD)" + std::string(strerror(errno)));
        throw std::runtime_error("Executor::changeFlags(), epoll_ctl(EPOLL_CTL_MOD) failed");
    }
}

void Executor::removeHandler(int fd) {
    if (handlers.find(fd) == handlers.end()) {
        return;
    }
    handlers.erase(fd);
    int r = epoll_ctl(globalfd, EPOLL_CTL_DEL, fd, 0);
    if (r == -1) {
        logger.error("An error occurred in Executor::removeHandler() in epoll_ctl(EPOLL_CTL_DEL)" + std::string(strerror(errno)));
        throw std::runtime_error("Executor::removeHandler(), epoll_ctl(EPOLL_CTL_DEL) failed");
    }
}

int Executor::execute() {
    while (true) {
        int eventsCount = epoll_wait(globalfd, events.data(), events.size(), -1);
        if (eventsCount == -1) {
            logger.error("An error occurred in Executor::execute() in epoll_wait()" + std::string(strerror(errno)));
            throw std::runtime_error("Executor::execute(), epoll_wait() failed");
        }
        bool stop = false;
        for (int i = 0; i < eventsCount; ++i) {
            if (events[i].data.fd == sigfd) {
                stop = true;
                break;
            }
        }
        if (stop) {
            break;
        }
        for (int i = 0; i < eventsCount; ++i)
            handlers[events[i].data.fd](events[i]);
    }
    return 0;
}

Executor::~Executor() {
    int r = ::close(globalfd);
    assert(r == 0);
    r = ::close(sigfd);
    assert(r == 0);
}
