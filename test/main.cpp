#include <cstdio>
#include <cstring>
#include "../hexlib.h"


int
main(void)
{
	char str[100] = {0};
	puts("--- decimal to hex ---");
	puts(dec2hex(str, 1024, 8)); /* 8 digits (00000400)*/

	memset(str, '\0', 100); /* reset array */
	puts(dec2hex(str, 255, 2)); /* 2 digits (FF)*/
	puts("");

	/* 4 byte (hex) (0x0f, 0xff, 0xff, 0xf0) or (015, 255, 255, 240)
	 */
	char hex[] = "0ffffff0";
	unsigned char raw[4];
	puts("--- hex to raw (byte array) ---");
	hex2raw(raw, hex);

	for (int i = 0; i < 4; i++)
		printf("%02X ", raw[i]);

	puts("\n");

	unsigned char byte[4] = {0xEE, 0xEE, 0xFF, 0x0A};
	char bf[12] = {0};
	puts("--- raw to hex ---");
	puts(raw2hex(bf, byte, 4)); /* 8 digits (EEEEFF0A) */
	puts("");

	char x[100] = {0};
	char msg[] = "hello world!";
	puts("--- ASCII to hex ---");
	puts(ascii2hex(x, msg, strlen(msg))); /* 68656C6C6F20776F726C6421 */

	return 0;
}

