#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "socket_t.h"
#include "ssl_util.h"

void print_errno() {
    fprintf(stderr, "Error: %s\n", strerror(errno));
}

int main(int argc, char **argv) {
    socket_p s;
    SSL_CTX *ctx;

    if(socket_new(PROTO_TCP) == NULL) {
        print_errno();
        return EXIT_FAILURE;
    }

    init_openssl();
    if((ctx = create_context()) == NULL) {
        socket_close(s);
        cleanup_openssl();
        return EXIT_FAILURE;
    }
        
    if(!configure_context(ctx)) {
        socket_close(s);
        cleanup_openssl();
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    socket_close(s);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return EXIT_SUCCESS;
}