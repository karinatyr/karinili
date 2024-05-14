#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;
void *mythread(void *dummy){
	pthread_t mythid;
	mythid = pthread_self();
	a = a+1;
	printf("thread %ld,результат вычисления  a=%d\n", mythid, a);
	return NULL;
}

int main(){

	pthread_t thid, mythid;
	int result;
	result = pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL);
	if(result != 0){
		printf("ошибка при создании нового thread\'a, возвращенное значение = %d\n", result);
		exit(-1);
	}
	printf("thread создан, thid = %ld\n",thid);
	mythid = pthread_self();
	 a = a + 1;
	printf("thread %ld результат вычисления a=%d\n", mythid, a);
	pthread_join(thid, (void **)NULL);
	return 0;
}

