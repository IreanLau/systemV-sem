#include"sem_lock.h"
static int sem_creat_get(int nsems,int flags)
{
	key_t _key = ftok(PATH,ID);
	if(_key < 0)
	{
		perror("ftok");
		return -1;
	}

	 return semget(_key,nsems,flags);
}
int sem_creat(int nsems)
{
	return sem_creat_get(nsems,IPC_CREAT | IPC_EXCL| 0777);
}
int sem_get(int nsems)
{
	return sem_creat_get(0,IPC_CREAT);
}

int sem_init(int sem_id,int sem,int val)
{
	semun_t semval;
	semval.val =val;
	return semctl(sem_id,sem,SETVAL,semval);
}

static int my_sem_op(int sem_id,int sem,int op)
{
	struct sembuf _op;
	_op.sem_num = sem;
	_op.sem_op = op;//传-1，减1
	_op.sem_flg = 0;//SEM_UNDO  (撤销)?  深入linux内核最后一章

	return semop(sem_id,&_op,1);
}

int sem_p(int sem_id,int sem)
{
	return my_sem_op(sem_id,sem,-1);
}

int sem_v(int sem_id,int sem)
{
	return my_sem_op(sem_id,sem,1);
}

int sem_destroy(int sem_id)
{

	return semctl(sem_id,0,IPC_RMID,NULL);
}

#ifdef _DEBUG_

int main()
{
	int nsems =12;
	int sem_id  = sem_creat(nsems);
	sleep(3);
    seminit(sem_id,0,1);
	
	
	sem_p(sem_id,0);
	sleep(1);
	sem_v(sem_id,0);

	sem_destroy(sem_id);
	return 0;
}

#endif




