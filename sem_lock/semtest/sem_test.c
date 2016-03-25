#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include"sem_lock.h"

int main()
{
	
   int sem_id = sem_creat(1);
   sem_init(sem_id,0,1);

	pid_t id =fork();
	if(id<0)
	{
		perror("fork");
		exit(1);
	}
	else if(id==0)
	{

	 int sem_id_child = sem_get(1);
		while(1)
		{
			
		 sem_p(sem_id_child,0);

			printf("A");
			fflush(stdout);
			sleep(1);
			printf("A");
			fflush(stdout);
			sleep(3);

		 sem_v(sem_id_child,0);
		}
		exit(0);
	}

	else
	{
		while(1)
		{
			sem_p(sem_id,0);

			printf("B");
			fflush(stdout);
			sleep(2);
			printf("B");
			fflush(stdout);
			sleep(1);

			sem_v(sem_id,0);
		}

	wait(NULL);
		
	 sem_destroy(sem_id);
	}
	return 0;
}
