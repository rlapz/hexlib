#ifndef HEXLIB_H
#define HEXLIB_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int8_t *dec2hex(int8_t *dest, const uint32_t value, size_t len);
int32_t byte2dec(const uint32_t *value, size_t len);
int8_t *ascii2hex(int8_t *dest, const int8_t *value, size_t len);
uint8_t *hex2byte(uint8_t *dest, const int8_t *value);
int8_t *byte2hex(int8_t *dest, const uint8_t *value, size_t len);


#endif
