#include <stdio.h>
#include <stdlib.h>

#include "../mapEditor/map.h"

char Tilepalette[] = {'.','#','@','/',92,'+','=' };

void map_drawTile(_S_MAP_OBJECT *pObj,int posx,int posy,_S_MAP_OBJECT *pTarget)
{
//	_S_MAP_OBJECT *pObj = &humanObj;
//	_S_MAP_OBJECT *pTarget = &screenBuf;
//	int posx = 5;
//	int posy = 5;

	for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
		for(int ix = 0; ix < pObj->m_header.m_nWidth;ix++) {
			map_PutTile(pTarget,ix + posx,iy + posy,
					pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
		}
	}

}

void map_drawTile_mirror(_S_MAP_OBJECT *pObj,int posx,int posy,_S_MAP_OBJECT *pTarget) 
{	
	for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
		for(int ix = 0; ix < pObj->m_header.m_nWidth;ix++) {
			map_PutTile(pTarget,ix + posx,iy + posy,
					pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
		}
	}

}

int main()
{
	_S_MAP_OBJECT screenBuf;
	map_init(&screenBuf);
	map_new(&screenBuf,16,16);

	_S_MAP_OBJECT humanObj;
	map_init(&humanObj);
	map_load(&humanObj,"human.dat");
	puts("\r\n-----------------------");
	map_drawTile(&humanObj,5,5,&screenBuf);
	map_dump(&screenBuf,Tilepalette);

	return 0;
}
