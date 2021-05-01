#include "hexlib.h"


static int8_t
get_dec(const int8_t *c)
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

int8_t *
dec2hex(int8_t *dest, uint32_t value, uint32_t len)
{
	char hex[] = "0123456789ABCDEF";
	uint32_t iter = 0;
	while (iter < len) {
		dest[iter] = '0';
		iter++;
	}
	dest[iter] = '\0';

	while (value > 0) {
		dest[len-1] = hex[0xf & value];
		value >>= 4;
		len--;
	}

	return dest;
}

uint8_t *
hex2raw(uint8_t *dest, const int8_t *value)
{
	uint8_t c;
	int8_t *tmp = (int8_t*)value;
	while (*tmp) {
		c = get_dec(tmp);
		c <<= 4;
		tmp++;
		c |= get_dec(tmp);
		*dest = c;
		tmp++;
		dest++;
	}
	return dest;
}

int8_t *
raw2hex(int8_t *dest, const uint8_t *value, uint32_t len)
{
	uint32_t i = 0, j = 0;
	int8_t hex[] = "0123456789ABCDEF";
	for (; i < len; i++, j += 2) {
		dest[j + 0] = hex[0xf & (value[i] >> 4)];
		dest[j + 1] = hex[0xf & value[i]];
	}
	dest[j] = '\0';
	return dest;
}

