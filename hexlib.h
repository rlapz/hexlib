#ifndef HEXLIB_H
#define HEXLIB_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void int_to_hex(char* dest, const char* format,
		int* value, size_t len);
void str_to_hex(char* dest, const char* value,
		size_t len);
void hex_to_byte(unsigned char* dest, char* value,
		size_t len);
void byte_to_hex(char* dest, const char *format,
		unsigned char* value, size_t len);

#endif
