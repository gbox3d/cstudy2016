#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"
#include "exit_room.h"

int main()
{
	char cmd;
	int bLoop = 1;

	while(bLoop) {
		printf("명령을 선택하세요,\r\n \
i(up),j(left),k(right),\r\n \
m(down),s(show map),x(exit)\r\n");
		
		for(int i=0;i<64;i++) {
			buffer_map[i] = world_map[i];
		}

		scanf("%c",&cmd);
		getchar();
		move_player(cmd);
		buffer_map[ player_xpos + player_ypos*8 ] = 3;

		switch(cmd) {
			case 's':
				map_drawAll(buffer_map);
				break;
			case 'x':
				bLoop = 0;
				printf("bye bye~\r\n"); 
				break;
		}

	}


	return 0;
}
