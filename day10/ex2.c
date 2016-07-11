#include <stdio.h>

char pstr[] = {
	0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,
	0,0,1,0,0,0,0,0,
	0,0,1,0,0,0,0,0,
	0,0,1,0,0,0,0,0,
	0,1,0,0,0,0,1,0,
	0,1,0,0,0,1,1,0,
	0,1,0,0,1,1,1,0
};

void putTile(int sy,int ey,
int sx, int ex,
char *ptrBuf)
{
	int ix,iy;

	for(iy=sy;iy<ey;iy++) {
		for(ix=sx;ix<ex;ix++) {
			if(pstr[ (iy*8)+ix] ==0 ) {
				putchar('.');
			}
			else {
				putchar('@');
			}
		}
		puts("");
	}
}

int main() {
	putTile(6,10,4,8,pstr);
}
