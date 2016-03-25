#ifndef _SEM_LOCK_
#define _SEM_LOCK_

#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define PATH "."
#define ID 0x6666

typedef union _semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
}semun_t;

//struct sembuf
//{
//	unsigned short int sem_num;
//	short int sem_op;
//	short int sem_flg;
//};

int sem_creat(int);
int sem_init(int,int,int);
int sem_get(int);
int sem_p(int,int);
int sem_v(int,int);
int sem_destroy(int);

#endif
