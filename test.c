#include <stdio.h>
#include "hexlib.h"


int main(void)
{
	const char *hex = "EF0101";

	unsigned char buffer[5];

	hex_to_byte(buffer, hex);

	for (int i=0; i<3; i++)
		printf("%02x", buffer[i]);

	puts("");

	char bf[7];

	byte_to_hex(bf, buffer, strlen(buffer));
	printf("%s\n", bf);
	puts("");

	const char *txt = "hello";
	char h[10];
	str_to_hex(h, txt, 5);

	printf("%s\n", h);
	puts("");

	return 0;
}
