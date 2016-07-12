#ifndef __MAP_H__
#define __MAP_H__

typedef struct {
	int m_nSkima;
	int m_nWidth;
	int m_nHeight;
}_S_MAP_HEADER;

typedef struct {
	_S_MAP_HEADER m_header;
	char *m_pBuf;
}_S_MAP_OBJECT;

void map_dump(_S_MAP_OBJECT *pObj,
char *pTile_pal)
{
	putTile(
			0,pObj->m_header.m_nHeight,
			0,pObj->m_header.m_nWidth,
			pObj->m_header.m_nWidth,
			pObj->m_pBuf,
			pTile_pal	
		   );
}

void map_new(_S_MAP_OBJECT *pObj,
		int nWidth,int nHeight)
{
	int nSize = nWidth*nHeight; 
	if(pObj->m_pBuf !=NULL) {free(pObj->m_pBuf); }
	pObj->m_header.m_nWidth =  nWidth;// atoi(strtok(NULL," "));
	pObj->m_header.m_nHeight = nHeight;//atoi(strtok(NULL," "));
	pObj->m_pBuf = malloc( nSize);

	for(int i=0;i< nSize ;i++) {
		pObj->m_pBuf[i] = 0;
	}

}

#endif
