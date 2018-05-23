#ifndef PORTS_H
#define PORTS_H

#include <stdint.h>
#include "common.h"

APIDEC unsigned char port_byte_in (uint16_t port);
APIDEC void port_byte_out (uint16_t port, uint8_t data);
APIDEC unsigned short port_word_in (uint16_t port);
APIDEC void port_word_out (uint16_t port, uint16_t data);

#endif
