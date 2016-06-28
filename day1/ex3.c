#include <stdio.h>

int main() 
{
	printf("hello \r\n");
	printf("\x1b[31m");
	printf("hello \r\n");
	printf("\x1b[1;31m");
	printf("hello vt100\r\n");
	printf("\x1b[1;32;43m");
	printf("blink\x1b[0m\r\n");
	//printf("\x1b[0m");	
	return 0;
}
