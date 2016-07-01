#ifndef __EXIT_ROOM_H__
#define __EXIT_ROOM_H__
int world_map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,0,1,0,0,0,2,
	1,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int buffer_map[64];

//0 준비
//1 게임 플레이
//2 레벨클리어
//3 게임오버 
int nFSM = 0;

int player_xpos;
int player_ypos;

void move_player(char cmd)
{
	int old_xpos = player_xpos;
	int old_ypos = player_ypos;

	switch(cmd)
	{
		case 'i':
			player_ypos -=1;
			break;
		case 'j':
			player_xpos -=1;
			break;
		case 'k':
			player_xpos += 1;
			break;
		case 'm':
			player_ypos += 1;
			break;
	}

	switch(buffer_map[ player_xpos + player_ypos*8 ] ) {
		case 1: //벽
		player_ypos = old_ypos;
		player_xpos = old_xpos;

		break;
		case 0: //공간
		break;
		case 2: //문 
		printf("미션 클리어 \r\n");
		nFSM = 2;
		break;

	}
	
	buffer_map[ player_xpos + player_ypos*8 ] = 3;

}

#endif

