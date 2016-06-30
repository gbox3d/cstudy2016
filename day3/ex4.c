#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int main()
{
	system("clear");

	int i=0;
	setColor(37,41);
	while(i<10) {
		gotoxy(10,i);
		printf(" ");
		i++;
	}
	gotoxy(0,20);
	setColor(0,0);
	printf("=============================");
	return 0;
}
