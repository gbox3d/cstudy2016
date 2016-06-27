
#include<stdio.h>
//gotoxy function
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}
void main ()
{

	gotoxy(25,50); //reposition cursor
	


	printf("hello world"); //display text
	printf("\x1b[31mThis is red text\x1b[0m\n");
	printf("\x1b[32mThis is green text\x1b[0m\n");
	
}
