#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <stdint.h>
#include "select_group.h"

typedef void(send_t)(void *driver, uint8_t *data, size_t length);
typedef size_t(recv_t)(void *driver, uint8_t *buf, size_t buf_length);
typedef void(close_t)(void *driver);
typedef void(cleanup_t)(void *driver);

typedef struct
{
  void      *driver;

  send_t    *driver_send;
  recv_t    *driver_recv;
  close_t   *driver_close;
  close_t   *driver_cleanup;

  size_t max_packet_size;

} driver_t;

driver_t *driver_get_tcp(char *host, uint16_t port, select_group_t *group);

void   driver_send(driver_t *driver, uint8_t *data, size_t length);
size_t driver_recv(driver_t *driver, uint8_t *buf, size_t buf_length);

#endif
