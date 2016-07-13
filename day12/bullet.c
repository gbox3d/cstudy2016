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

#include "bullet.h"

void bullet_init(S_BULLET_OBJECT *pObj,
double x,double y,double speed,
_S_MAP_OBJECT *pBody)
{

	pObj->m_fSeepd = speed;
	pObj->m_fXpos = x;
	pObj->m_fYpos = y;
	pObj->m_pBody = pBody;

}

void  bullet_apply(S_BULLET_OBJECT *pObj,double deltaTick)
{
	pObj->m_fYpos += deltaTick * pObj->m_fSeepd;
}

void bullet_draw(S_BULLET_OBJECT *pObj,_S_MAP_OBJECT *pMapBuf)
{
	map_drawTile_trn(pObj->m_pBody,
		(int)pObj->m_fXpos,
		(int)pObj->m_fYpos,
		pMapBuf);
}

