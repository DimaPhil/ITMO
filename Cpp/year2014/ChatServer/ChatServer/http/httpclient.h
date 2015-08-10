#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <tcp/tcpsocket.h>
#include <http/httprequest.h>
#include <http/httpresponse.h>

class HttpClient
{
private:
    Executor *executor;
public:
    typedef std::function<void(HttpResponse)> ResponseHandler;
    enum RequestStatus {SUCCESS, UNKNOWN_HOST};

    //std::map<HttpObject*, std::shared_ptr<HttpObject>> objects;
    HttpClient(Executor *executor);
    RequestStatus request(const HttpRequest &request, const ResponseHandler &handler = ResponseHandler());
};

#endif // HTTPCLIENT_H
