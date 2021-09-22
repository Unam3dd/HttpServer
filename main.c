#include <stdio.h>
#include <stdlib.h>
#include "http_server.h"
#include "log.h"

int main(int argc, char **argv)
{
    http_server_t server;

    http_server_initialize(&server);

    server.addr = argv[1];
    server.port = atoi(argv[2]);

    if (server.start(&server))
        print_error();
    
    server.wait(&server);
    
    server.close(&server);

    http_server_destroy(&server);

    return (0);
}