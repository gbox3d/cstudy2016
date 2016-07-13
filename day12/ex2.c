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

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer;
_S_MAP_OBJECT gF22Raptor;
int xpos,ypos;

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	system("clear");
	map_init(&gScreenBuffer);
	map_new(&gScreenBuffer,35,16);

	map_init(&gF22Raptor);
	map_load(&gF22Raptor,"plane1.dat");
	xpos = 17;ypos = 10;

	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간 입력
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
			else if(ch == 'w' ) {
				ypos -=1;
			}
			else if(ch == 's') {
				ypos +=1;
			}else if(ch == 'a') {
				xpos -=1;
			}else if(ch == 'd') {
				xpos +=1;
			}


		}

		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {

			map_drawTile_trn(&gF22Raptor,xpos,ypos,&gScreenBuffer);

			gotoxy(0,0);
			puts("----------------------------------\r");
			map_dump(&gScreenBuffer,Default_Tilepalete);
			puts("----------------------------------\r");

			puts("move : w,a,s,d \r");
			puts("quit : q \r");
			
			acc_tick = 0;
		}

	}

	return 0;

}
