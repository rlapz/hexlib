#include <stdio.h>
#include "../hexlib.h"


int
main(void)
{
	char str[100] = {0};
	puts("--- decimal to hex ---");
	puts(dec2hex(str, 8192, 4));
	puts("");
	puts(dec2hex(str, 127, 4));
	puts("");

	char *hex = "0ffffff0"; /* 4 byte */
	unsigned char raw[4];
	puts("--- hex to raw (byte array) ---");
	hex2raw(raw, hex);

	for (int i = 0; i < 4; i++)
		printf("%d ", raw[i]);

	puts("\n");

	unsigned char byte[4] = {0xEE, 0xEE, 0xFF, 0x0A};
	char bf[12] = {0};
	puts("--- raw to hex ---");
	puts(raw2hex(bf, byte, 4));
	puts("");

	char x[100] = {0};
	puts("--- ASCII to hex ---");
	puts(ascii2hex(x, "hello", 5));

	return 0;
}

