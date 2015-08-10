#include "logger.h"

Logger::Logger() {
}

void Logger::info(const std::string &message) {
    fprintf(stderr, "INFO: %s\n", message.c_str());
}

void Logger::error(const std::string &message) {
    fprintf(stderr, "\033[0;31mERROR: %s\033[0m\n", message.c_str());
}

void Logger::status(const std::string &message) {
    fprintf(stderr, "\033[0;32mStatus: %s\033[0m\n", message.c_str());
}

void Logger::status(int exitCode) {
    if (exitCode == 0) {
        fprintf(stderr, "\033[0;32mStatus: %d\033[0m\n", exitCode);
    } else {
        fprintf(stderr, "\033[0;31mStatus: %d\n033[0m\n", exitCode);
    }
}


