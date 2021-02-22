#include "hexlib.h"


static int hex_val(int c)
{
	switch(c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'a': case 'A': return 10;
		case 'b': case 'B': return 11;
		case 'c': case 'C': return 12;
		case 'd': case 'D': return 13;
		case 'e': case 'E': return 14;
		case 'f': case 'F': return 15;
	}
	return -1;
}

void int_to_hex(char* dest, const char* format,
		int* value, size_t len)
{
	char buffer[len];
	snprintf(buffer, len, format, *value);
	strcpy(dest, buffer);
}

void str_to_hex(char* dest,
		const char *value, size_t len)
{
	char buffer[len*2];
	size_t i, j = 0;

	for (i = 0, j = 0; i < len; i++, j += 2) {
		sprintf(j > 0 ? buffer+j : buffer, "%02X", value[i]);
	}
	strcpy(dest, buffer);
}

void hex_to_byte(unsigned char* dest, const char* value)
{
	size_t len = strlen(value)/2;
	int c;
	while (*value) {
		c = hex_val(*value);
		value++;
		c = c << 4;
		c |= hex_val(*value);
		value++;
		*dest = c;
		dest++;
	}
}

void byte_to_hex(char* dest,
		const unsigned char* value, size_t len)
{
	size_t i, j;
	static const char hex[] = "0123456789abcdef";
	for (i = 0, j = 0 ; i < len; i++, j += 2) {
		dest[j + 0] = hex[0xf & (value[i] >> 4)];
		dest[j + 1] = hex[0xf & value[i]];
	}
	dest[j] = 0;
}
