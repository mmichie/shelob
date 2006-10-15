#ifndef SHELOB_HTTP_H
#define SHELOB_HTTP_H 1

#include <map>
#include <vector>
#include <signal.h>
#include <sys/wait.h>

#include "global.h"

#include "token.h"
#include "filter.h"
#include "socket.h"
#include "log.h"
#include "mime.h"
#include "cgi.h"

class Http {

private:
    void printDate(void);
    void printServer(void);
    void printContentType(string type);
    void printContentLength(int size);
    void printConnectionType(bool keep_alive=false);
	string sanitizeFilename(string filename);
    void sendFile(map<string, string> headermap, string request_line, bool keep_alive = false, 
                  bool head_cmd = false);

public:
    void sendHeader(int code, int size, string file_type = "text/plain", 
		    		bool keep_alive = false);
    string getHeader();
    void start(int server_port);
    void parseHeader(string header);

    Socket *sock;        
};

#endif /* !SHELOB_HTTP_H */
