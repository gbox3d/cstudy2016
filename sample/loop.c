#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>


struct termios orig_termios;

void reset_terminal_mode()
{
	tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
	struct termios new_termios;

	/* take two copies - one for now, one for later */
	tcgetattr(0, &orig_termios);
	memcpy(&new_termios, &orig_termios, sizeof(new_termios));

	/* register cleanup handler, and set the new terminal mode */
	atexit(reset_terminal_mode);
	cfmakeraw(&new_termios);
	tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}

int getch()
{
	int r;
	unsigned char c;
	if ((r = read(0, &c, sizeof(c))) < 0) {
		return r;
	} else {
		return c;
	}
}

int main(int argc, char *argv[])
{
	struct timespec work_timer;
	set_conio_terminal_mode();
	double last_tick = 0;
	double acc_tick = 0;

	int bLoop = 1;

	while(bLoop) {

		clock_gettime(CLOCK_MONOTONIC,&work_timer);

		double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		acc_tick += delta_tick;
		
		last_tick = cur_tick;
		
		if(acc_tick > 1.0) {
			printf("tick tok \r\n");
			acc_tick = 0;
		}


		
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 3) {
				bLoop = 0;
			}
			printf("%d \r\n",(int)ch);
		}
		printf("%f \r",acc_tick);
	}
	return 0;

}
/*
int main(int argc, char *argv[])
{
	struct timespec t2, t3;
	double dt1;

	volatile long long i;

	clock_gettime(CLOCK_MONOTONIC,  &t2);
	for (i=0; i<1e9; i++) {};
	clock_gettime(CLOCK_MONOTONIC,  &t3);
	//time in seconds
	dt1 = (t3.tv_sec - t2.tv_sec) + (double) (t3.tv_nsec - t2.tv_nsec) * 1e-9;
	printf("timer : %f\n", dt1);
	
	

	
	return 0;
}
*/



