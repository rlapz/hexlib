#ifndef HEXLIB_H
#define HEXLIB_H

#include <stdint.h>

int8_t *dec2hex(int8_t *dest, uint32_t value, uint32_t len);
uint8_t *hex2raw(uint8_t *dest, const int8_t *value);
int8_t *raw2hex(int8_t *dest, const uint8_t *value, uint32_t len);


#endif
