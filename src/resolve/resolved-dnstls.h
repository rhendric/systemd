/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#if ENABLE_DNS_OVER_TLS

#include <stdbool.h>
#include <stdint.h>

typedef struct DnsServer DnsServer;
typedef struct DnsStream DnsStream;
typedef struct DnsTlsManagerData DnsTlsManagerData;
typedef struct DnsTlsServerData DnsTlsServerData;
typedef struct DnsTlsStreamData DnsTlsStreamData;
typedef struct Manager Manager;

#if DNS_OVER_TLS_USE_GNUTLS
#include "resolved-dnstls-gnutls.h"
#elif DNS_OVER_TLS_USE_OPENSSL
#include "resolved-dnstls-openssl.h"
#else
#error Unknown dependency for supporting DNS-over-TLS
#endif

#define DNSTLS_STREAM_CLOSED 1

int dnstls_stream_connect_tls(DnsStream *stream, DnsServer *server);
void dnstls_stream_free(DnsStream *stream);
int dnstls_stream_on_io(DnsStream *stream, uint32_t revents);
int dnstls_stream_shutdown(DnsStream *stream, int error);
ssize_t dnstls_stream_write(DnsStream *stream, const char *buf, size_t count);
ssize_t dnstls_stream_read(DnsStream *stream, void *buf, size_t count);
bool dnstls_stream_has_buffered_data(DnsStream *stream);

void dnstls_server_free(DnsServer *server);

int dnstls_manager_init(Manager *manager);
void dnstls_manager_free(Manager *manager);

#endif /* ENABLE_DNS_OVER_TLS */
