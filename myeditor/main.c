#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int bLoop;
void me_exit();
void me_push();
void me_dump();

int main()
{
	puts("myeditor version 1.0");

	while(bLoop)
	{
		char strCmd[128];
		gets(strCmd);

		char *pTemp = strtok(strCmd," ");

		if(!strcmp(pTemp,"exit")) {
			me_exit();
		}
		else if(!strcmp(pTemp,"push")) {
			me_push();
		}
		else if(!strcmp(pTemp,"pop")) {
		}
		else if(!strcmp(pTemp,"del")) {
		}
		else if(!strcmp(pTemp,"ins")) {
		}
		else if(!strcmp(pTemp,"rm")) {
		}
		else if(!strcmp(pTemp,"set")) {
		}
		else if(!strcmp(pTemp,"dump")) {
			me_dump();
		}

	}
	return 0;

}

