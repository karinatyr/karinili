#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
 int main(){
	int semid;
	char pathname[] = "forftok.ipc";
	key_t key;
	struct sembuf mybuf;
	if ((key = ftok(pathname, 0)) < 0) {
		printf("не удалось сгенерировать ipc-ключ\n");
		exit(-1);
	}
	if((semid = semget(key, 1, 0666 |IPC_CREAT)) < 0 ){
		printf("не удалось получить доступ к массиву семафоров\n");
		exit(-1);
	}
	mybuf.sem_op = -1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	if(semop(semid, &mybuf, 1) <0){
		printf("не удалось выполнить операцию над семафором 0\n");
		exit(-1);
	}
	printf("условие установлено\n");
	return 0;
}
