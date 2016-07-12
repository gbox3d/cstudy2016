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

void map_PutTile(_S_MAP_OBJECT *pObj, int x,int y,int nTileIndex)
{
	pObj->m_pBuf[ pObj->m_header.m_nWidth * y + x  ] = nTileIndex;
}

//0 : 성공
//1 : 실패 
int map_save(_S_MAP_OBJECT *pObj,char *filename)
{
	FILE *pf = fopen(filename,"wb");
	fwrite( &( pObj->m_header),sizeof(pObj->m_header),1,pf);
	int nSize = pObj->m_header.m_nWidth * pObj->m_header.m_nHeight;
	fwrite(pObj->m_pBuf,nSize,1,pf);

	fclose(pf);
	return 0;

}
//0: success
//1 : error
int map_load(_S_MAP_OBJECT *pObj,char *filename)
{
	FILE *pf = fopen(filename,"rb");
	fread( &(pObj->m_header),sizeof(_S_MAP_HEADER),1,pf);

	if(pObj->m_pBuf) {
		free(pObj->m_pBuf);
	}
	int nSize = pObj->m_header.m_nWidth * pObj->m_header.m_nHeight;
	pObj->m_pBuf = malloc( nSize);

	fread(pObj->m_pBuf,nSize,1,pf);

	for(int i=0;i<nSize;i++) {
		printf("%d,",pObj->m_pBuf[i]);
	}

	return 0;
}



#endif
