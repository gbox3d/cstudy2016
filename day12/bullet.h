#ifndef __BULLET_H__
#define __BULLET_H__

typedef struct {
	double m_fXpos;
	double m_fYpos;
	double m_fSeepd;

	_S_MAP_OBJECT *m_pBody;

} S_BULLET_OBJECT;

void bullet_init(S_BULLET_OBJECT *pObj,double x,double y,double speed,_S_MAP_OBJECT *pBody);
void  bullet_apply(S_BULLET_OBJECT *pObj,double deltaTick);
void bullet_draw(S_BULLET_OBJECT *pObj,_S_MAP_OBJECT *pMapBuf);


#endif
