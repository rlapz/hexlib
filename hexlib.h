#ifndef HEXLIB_H
#define HEXLIB_H

#include <stddef.h>

char		*dec2hex(char *dest, int value, size_t len);
unsigned char	*hex2raw(unsigned char *dest, const char *value);
char		*raw2hex(char *dest, const unsigned char *value, size_t len);
char		*ascii2hex(char *dest, const char *value, size_t len);

#endif
