#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int bLoop;
extern char *pTemp;
extern char strCmd[];

void me_exit();

int main()
{
	puts("myeditor version 1.0");


	while(bLoop)
	{
		gets(strCmd);

		pTemp = strtok(strCmd," ");

		if(!strcmp(pTemp,"exit")) {
			me_exit();
		}
		else if(!strcmp(pTemp,"push")) {
		}
		else if(!strcmp(pTemp,"pop")) {
		}
		else if(!strcmp(pTemp,"del")) {

		}
		else if(!strcmp(pTemp,"ins")) {
			int nIndex = atoi(strtok(NULL," "));
			pTemp = strtok(NULL,"");
			printf("%d , %s 추가 \r\n",nIndex,pTemp);

		}
		else if(!strcmp(pTemp,"rm")) {
			int nIndex = atoi(strtok(NULL,""));
		}
		else if(!strcmp(pTemp,"set")) {
			//set 1 new string
			int nIndex = atoi(strtok(NULL," "));
		}
		else if(!strcmp(pTemp,"dump")) {
		}

	}


	return 0;
}

