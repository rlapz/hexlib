#include "hexlib.h"


static const char  hexlist[] = "0123456789ABCDEF";

static char
get_decimal(const char *c)
{
	switch (*c) {
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

char *
dec2hex(char *dest, int value, size_t len)
{
	size_t iter = 0, len_tmp = len;
	while (value > 0 && len > 0) {
		if (iter < len_tmp) {
			/* fill leading by zero */
			dest[iter] = '0';
			iter++;
			continue;
		}
		dest[len-1] = hexlist[0xf & value];
		value >>= 4;
		len--;
	}
	return dest;
}

unsigned char *
hex2raw(unsigned char *dest, const char *value)
{
	char c;
	while (*value != '\0') {
		c = get_decimal(value);
		c <<= 4;
		value++;
		c |= get_decimal(value);
		*dest = (unsigned char)c;
		value++;
		dest++;
	}
	return dest;
}

char *
raw2hex(char *dest, const unsigned char *value, size_t len)
{
	size_t i = 0, j = 0;
	for (; i < len; i++, j += 2) {
		dest[j + 0] = hexlist[0xf & (value[i] >> 4)];
		dest[j + 1] = hexlist[0xf & value[i]];
	}
	dest[j] = '\0';
	return dest;
}

char *
ascii2hex(char *dest, const char *value, size_t len)
{
	return raw2hex(dest, (const unsigned char*)value, len);
}

