#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "logger.h"

#include <sys/epoll.h>

#include <functional>
#include <map>
#include <vector>

using namespace std;

class Executor {
private:
    typedef std::function <void(epoll_event)> EventHandler;
    const int MAX_EVENTS;

    Logger logger;
    int globalfd;
    int sigfd;
    std::vector<epoll_event> events;
    std::map<int, EventHandler> handlers;
public:
    Executor();
    ~Executor();

    int setHandler(int fd, EventHandler handler, uint32_t flags);
    void removeHandler(int fd);
    void changeFlags(int fd, uint32_t flags);
    int execute();
    void stop();
};

#endif // EXECUTOR_H
