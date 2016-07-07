#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myeditor.h"

int main()
{
	puts("myeditor version 1.0");

	_S_STR_LINE *pHeader = NULL;

	int bLoop = 1;
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
			pTemp = strtok(NULL,"");
			char *pstr = (char *)malloc(strlen(pTemp)+1);
			strcpy(pstr,pTemp);
			_S_STR_LINE *pLine = (_S_STR_LINE *)malloc(sizeof(_S_STR_LINE));
			pLine->m_szStr = pstr;
			pLine->m_pNext = NULL;
			if(pHeader == NULL) {
				pHeader = pLine;
			}
			else {
				
				_S_STR_LINE *pNext = (_S_STR_LINE *)pHeader;

				while(pNext != NULL) {
					if(pNext->m_pNext == NULL) {
						pNext->m_pNext = pLine;
						pNext = NULL;
					}
					else {
						pNext = pNext->m_pNext;
					}
				}
			}
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
			puts("---------------------------");
			

			puts("---------------------------");
		}

	}


	return 0;
}
