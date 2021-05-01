#include <stdio.h>
#include "../hexlib.h"


int
main(void)
{
	int8_t str[100] = {0};
	puts("--- decimal to hex ---");
	puts(dec2hex(str, 1200, 5));
	puts("");

	int8_t *hex = "FFFFFFFF"; /* 2 byte */
	uint8_t raw[4];
	puts("--- hex to raw (byte array) ---");
	hex2raw(raw, hex);

	for (int8_t i = 0; i < 4; i++)
		printf("%d ", raw[i]);

	puts("\n");

	uint8_t byte[4] = {0xEE, 0xEE, 0xFF, 0x0A};
	int8_t bf[12] = {0};
	puts("--- raw to hex ---");
	puts(raw2hex(bf, byte, 4));
	puts("");

	int8_t x[100] = {0};
	puts("--- ASCII to hex ---");
	puts(raw2hex(x, (int8_t*)"hello", 5));

	return 0;
}

