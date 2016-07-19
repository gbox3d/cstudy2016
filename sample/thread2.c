#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid;


void* doSomeThing(void *arg)
{
	unsigned long i = 0;
	pthread_t id = pthread_self();

/*
	if(pthread_equal(id,tid[0]))
	{
		printf("\n First thread processing\n");
	}
	else
	{
		printf("\n Second thread processing\n");
	}
*/
	while(1) 
	{
		puts("test");

		sleep(1);
	}


	return NULL;
}


int main(void)
{
	int i = 0;
	int err;


	{
		err = pthread_create(&tid, NULL, &doSomeThing, NULL);
		if (err != 0)
			printf("\ncan't create thread :[%s]", strerror(err));
		else
			printf("\n Thread created successfully\n");

	}


//	sleep(5);

	char ch = getchar();

	printf("%c \r\n",ch);
	
	return 0;
}

