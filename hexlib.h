/* GPL v2.0 License
 *
 * Copyright (c) 2021 Arthur Lapz (rLapz)
 */
#ifndef HEXLIB_H
#define HEXLIB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

char		*dec2hex(char *dest, int value, size_t len);
unsigned char	*hex2raw(unsigned char *dest, const char *value);
char		*raw2hex(char *dest, const unsigned char *value, size_t len);
char		*ascii2hex(char *dest, const char *value, size_t len);

#ifdef __cplusplus
}
#endif

#endif
