#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int bLoop = 1;
	char *strLine[128] = {0};
	int nTailIndex = 0;
	while(bLoop)
	{
		char *pTemp;
		char strCmd[128];
		gets(strCmd);
		
		pTemp = strtok(strCmd," ");

		if(!strcmp(pTemp,"exit")) {
			bLoop = 0;
		}
		else if(!strcmp(pTemp,"push")) {
			//push 원하는 문자열 
			pTemp = strtok(NULL,"");

			char *pstr = (char *)malloc(strlen(pTemp)+1);
			strcpy(pstr,pTemp);
			strLine[nTailIndex++] = pstr;
		}
		else if(!strcmp(pTemp,"pop")) {
			
		}
		else if(!strcmp(pTemp,"dump")) {
			
			puts("---------------------------");
			for(int i=0;strLine[i] != 0x00;i++) {
				puts(strLine[i]);
			}
			puts("---------------------------");
		}

	}


	return 0;
}
