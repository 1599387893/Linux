#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define PATH "."
#define PROJ_ID 0x6666
#define SHM_SIZE 4096

int main()
{
	key_t key = ftok(PATH,PROJ_ID);
	int id = shmget(key,SHM_SIZE,IPC_CREAT|IPC_EXCL);	//开辟共享内存空间(创建共享内存)
	if(id < 0)
	{
		perror("shmget error!");
		return -1;
	}

	char* shm_start = (char*)shmat(id,NULL,0);	//与共享内存建立映射关系
	if(shm_start ==(void*)-1)
	{
		perror("shmat error");
		return -1;
	}

	int i = 0;
	while(i < 26)
	{
		shm_start[i] = i+'A';
		sleep(1);
		i++;
	}
	shmdt(shm_start);	//与共享内存解除映射关系

	shmctl(id,IPC_RMID,NULL); //删除共享内存

	return 0;
}
