#include "../hexlib.h"

int
main(void)
{
	char tmp[100] = {0};
	uint32_t hex = 0xFF;

	printf("%d\n", byte2dec(&hex, sizeof(tmp)));
	printf("%s\n", dec2hex(tmp, 2000000000, sizeof(tmp)));

	int8_t byte[100];
	uint8_t h[] = {0xFF, 0xFF, 0xEE};
	byte2hex(byte, h, 3);
	printf("%s\n", byte);

	uint8_t b[3];
	int8_t test[] = "616364";

	hex2byte(b, test);
	printf("%c\n", b[0]);
	printf("%c\n", b[1]);
	printf("%c\n", b[2]);
	

	return 0;
}

