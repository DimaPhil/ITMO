#include "httpclient.h"
#include <http/httputils.h>

#include <memory>
#include <cassert>

HttpClient::HttpClient(Executor *executor) :
    executor(executor) {}

HttpClient::RequestStatus HttpClient::request(const HttpRequest &request,
                                              const ResponseHandler &handler) {
    assert(false);
    /*std::shared_ptr<TcpSocket> socket_ptr(new TcpSocket(executor));
    TcpSocket *socket = socket_ptr.get();
    //HttpResponse *obj = new HttpResponse(socket);
    //objects[obj] = std::shared_ptr<HttpObject>(obj);
    std::shared_ptr<HttpObject> obj;//(new HttpResponse(socket));

    HttpUtils::readHttp(obj, [=](std::shared_ptr<HttpObject> pointer) {
        std::shared_ptr<HttpResponse> httpObject(static_cast<HttpResponse*>(pointer.get()));
        if (handler) {
            //handler(*httpObject);
        }
    }, [=] (std::shared_ptr<HttpObject>) {}, [=](){ return new HttpResponse(socket);}
    );

    TcpSocket::ConnectedState state = socket->connectToHost(request.getHost());
    if (state == TcpSocket::UNKNOWN_HOST) {
        return UNKNOWN_HOST;
    }

    socket->write(request.toString());*/
    return SUCCESS;
}
