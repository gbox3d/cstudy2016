
#include<stdio.h>
#include <stdlib.h>
//gotoxy function
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}
int main ()
{
	system("clear");

	gotoxy(1,1); //reposition cursor

	printf("hello world"); //display text
	gotoxy(3,5);
	printf("\x1b[31mThis is red text\x1b[0m");
	gotoxy(1,2);
	printf("\x1b[32mThis is green text\x1b[0m");
	//맨마지막은 최대 범위에 그려준다.
	gotoxy(1,20);
	printf("============================== \r\n");
	return 0;

}
