#include "codec.h"

using namespace muduo;
using namespace muduo::net;
using namespace pubsub;

ParseResult pubsub::parseMessage(Buffer* buf, string* cmd, string* topic, string* content) {
    ParseResult result = kError;
    const char* crlf = buf->findCRLF();
    if (crlf)
    {
        const char* space = std::find(buf->peek(), crlf, ' ');
        if (space != crlf)
        {
            cmd->assign(buf->peek(), space);    
            if (*cmd == "pub")
            {
                topic->assign(space+1, crlf);
                const char* start = crlf + 2;
                crlf = buf->findCRLF(start);
                if (crlf)
                {
                    content->assign(start, crlf);
                    buf->retrieveUntil(crlf+2);
                    result = kSuccess;
                }
                else
                {
                    result = kContinue;
                }
            } else if (*cmd == "nodename") {
                content->assign(space+1, crlf);
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            } else if (*cmd == "sub") {
                topic->assign(space+1, crlf);
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            }
            else
            {
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            }
        }
        else
        {
            cmd->assign(buf->peek(), space);
            if (*cmd == "stepover") {
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            } else if (*cmd == "initover") {
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            } else if (*cmd == "synpubover") {
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            }
            else {
                result = kError;
            }
        }
    }
    else
    {
        result = kContinue;
    }
    return result;
}
