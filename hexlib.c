#include "hexlib.h"

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

void hex_to_byte(unsigned char* dest,
		char* value, size_t len)
{
	char* pos = value;
	char* endptr;
	size_t count = 0;

	for (count = 0; count < len; count++) {
		char buf[5] = {'0', 'x', pos[0], pos[1], '\0'};
		dest[count] = strtol(buf, &endptr, 0);
		pos += 2 * sizeof(char);
	}
}

void byte_to_hex(char* dest, const char *format,
		unsigned char* value, size_t len)
{
	char buffer[len];
	size_t i, j;

	for (i = 0, j = 0; i < len; i++, j += 2)
		sprintf(j > 0 ? buffer+j : buffer, format, value[i]);

	strcpy(dest, buffer);
}
