#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "plane.h"

void Plane_Apply(_S_Plane *pObj,double deltaTick,char key_input)
{
	switch(key_input)
	{
		case 'a':
		pObj->m_fXpos -= 1;
		break;
		case 'd':
		pObj->m_fXpos += 1;
		break;
		case 'w':
		pObj->m_fYpos -= 1;
		break;
		case 's':
		pObj->m_fYpos += 1;
		break;
	}
	
}
void Plane_Draw(_S_Plane *pObj, _S_MAP_OBJECT *pBuff)
{
	map_drawTile_trn(pObj->m_pBody,
	(int)pObj->m_fXpos,
	(int)pObj->m_fYpos,
	pBuff);
}

void Plane_init(_S_Plane *pObj,_S_MAP_OBJECT *pBody,double x,double y)
{
	pObj->m_pBody = pBody;
	pObj->m_fYpos = y;
	pObj->m_fXpos = x;
	
	pObj->pfApply = Plane_Apply;
	pObj->pfDraw = Plane_Draw;

}


