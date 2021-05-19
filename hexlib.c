#include "hexlib.h"


static const char  hexlist[] = "0123456789ABCDEF";

char *
dec2hex(char *dest, int value, size_t len)
{
	size_t iter = 0, len_tmp = len;
	while (iter < len_tmp) {
		if (value > 0) {
			dest[len-1] = hexlist[0xf & value];
			value >>= 4;
			len--;
			len_tmp--;
			continue;
		}
		dest[iter] = '0'; /* fill leading by zero */
		iter++;
	}
	return dest;
}

static unsigned char
get_hex(const char *c1, const char *c2)
{
	/* https://www.microchip.com/forums/FindPost/745864 */
	unsigned char ret;
	ret = ((*c1) <= 57 ? (*c1) - 48 : (0xf & ((*c1) - 97)) + 10) << 4;
	ret |= (*c2) <= 57 ? (*c2) - 48 : (0xf & ((*c2) - 97)) + 10;

	return ret;
}

unsigned char *
hex2raw(unsigned char *dest, const char *value)
{
	while (*value != '\0') {
		*dest = get_hex(value, value+1);
		value += 2;
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

