#include <executor.h>
#include <chat/chatserver.h>
#include <cassert>

int main(int, char**) {
    Executor executor;
    ChatServer server(&executor);
    Logger logger;
    logger.status(server.start(2390));
    return executor.execute();
}
