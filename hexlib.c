#include "hexlib.h"


static int8_t
get_byte(const int8_t *c)
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
dec2hex(int8_t *dest, const uint32_t value, size_t len)
{
	snprintf(dest, len, "%X", value);
	return dest;
}

int32_t
byte2dec(const uint32_t *value, size_t len)
{
	int8_t tmp[len];
	int32_t dest = 0;

	snprintf(tmp, len, "%d", *value);
	dest = strtol(tmp, NULL, 10);

	return dest;
}

int8_t *
ascii2hex(int8_t *dest, const int8_t *value, size_t len)
{
	int8_t tmp[len*2];
	size_t i = 0, j = 0;

	memset(tmp, '\0', sizeof(tmp));
	for (; i < len; i++, j += 2) {
		if (value[i] != '\0')
			snprintf(j > 0 ? tmp+j : tmp, 3,
					"%02X", value[i]);
	}
	strncpy(dest, tmp, len);
	return dest;
}

uint8_t *
hex2byte(uint8_t *dest, const int8_t *value)
{
	uint8_t c;
	int8_t *tmp = (int8_t*)value;
	while (*tmp) {
		c = get_byte(tmp);
		c = c << 4;
		tmp++;
		c |= get_byte(tmp);
		tmp++;
		*dest = c;
		dest++;
	}
	return dest;
}

int8_t *
byte2hex(int8_t *dest, const uint8_t *value, size_t len)
{
	size_t i = 0, j = 0;
	int8_t hex[] = "0123456789ABCDEF";
	for (; i < len; i++, j += 2) {
		dest[j + 0] = hex[0xf & (value[i] >> 4)];
		dest[j + 1] = hex[0xf & value[i]];
	}
	dest[j] = '\0';
	return dest;
}

