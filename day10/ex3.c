#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *pMapBuf;

void putTile(int sy,int ey,int sx, int ex,
int width,
char *ptrBuf)
{
	int ix,iy;

	for(iy=sy;iy<ey;iy++) {
		for(ix=sx;ix<ex;ix++) {
			if(ptrBuf[ (iy*width)+ix] ==0 ) {
				putchar('.');
			}
			else {
				putchar('@');
			}
		}
		printf("\r\n");
		//puts("");
	}
}
				
int main()
{
	int width,height;
	FILE *pf;
	pf = fopen("./ex2.data.txt","r");
	
	char buf[256];

	fgets(buf,256,pf);

	puts(buf);

	char *pTemp = strtok(buf,",");
	//puts(pTemp);
	width = atoi(pTemp);
	pTemp = strtok(NULL,",");
	//puts(pTemp);
	height = atoi(pTemp);

	pMapBuf = (char *)malloc(width*height);
	
	int ix,iy;
	for(iy = 0 ; iy < height;iy++) {
		fgets(buf,256,pf);
		pTemp = strtok(buf,",");
		pMapBuf[iy*width + 0] = atoi(pTemp);
		for(ix=1;ix < width;ix++) {
			pTemp = strtok(NULL,",");
			pMapBuf[iy*width + ix] = atoi(pTemp);
		}
	}
	
	putTile(0,height,0,width,width,pMapBuf);

	free(pMapBuf);
	fclose(pf);

}
