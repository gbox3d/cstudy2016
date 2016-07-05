#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//add 10,20
	//sub 5,2
	//mul 4,3
	//div 8,2
	
	char strCmd[128];

	scanf("%s",strCmd);

	//...
	char *ptrTemp;
	int a,b;
	
	ptrTemp = strtok(strCmd," ");

	if(strcmp(ptrTemp,"add") == 0) {
		printf("덧셈을...\r\n");
	}
	else if(strcmp(ptrTemp,"sub") == 0) {
		printf("뺄셈을...\r\n");
	}



	return 0;
}
