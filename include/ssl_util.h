#ifndef __SSL_UTIL__
#define __SSL_UTIL__

#include <stdbool.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

void init_openssl();
void cleanup_openssl();
SSL_CTX* create_context();
bool configure_context(SSL_CTX *ctx);

#endif