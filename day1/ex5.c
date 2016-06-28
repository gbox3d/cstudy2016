#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);

}

int main() 
{
	int fore_color;
	fore_color = 31;
	system("clear");
	//"\x1b[31m"
	//printf("%c[%dm",0x1b,fore_color);
	gotoxy(3,3);
	setColor(33,44);
	printf("hello");

	gotoxy(3,10);
	setColor(32,43);
	printf("world");
	setColor(0,0); //reset ansi command 

	gotoxy(20,1);
	printf("|");
	gotoxy(20,2);
	printf("|");
	gotoxy(20,3);
	printf("|");
	gotoxy(20,4);
	printf("|");
	gotoxy(20,5);
	printf("|");

	gotoxy(1,20);
	printf("===================================");
	return 0;
}
