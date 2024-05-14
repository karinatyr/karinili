#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;// инициализация глобальной статической переменной, доступной из каждого thread'а 
//функция выполняющая в рамказ второго thread'а
void *mythread(void *dummy){
	pthread_t mythid;//индификатор thread'a  - для каждого имеет свое  значение
	mythid = pthread_self();
	a = a+1;
	printf("thread %ld,результат вычисления  a=%d\n", mythid, a);//печать индификатора текущего thread'a и значения глобальной переменной 
	return NULL;
}

int main(){

	pthread_t thid, mythid;
	int result;
	result = pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL);//создание нового thread'a при помощи вызова функции my thread()
	if(result != 0){
		printf("ошибка при создании нового thread\'a, возвращенное значение = %d\n", result);
		exit(-1);
	}
	printf("thread создан, thid = %ld\n",thid);
	mythid = pthread_self();//сохраняем в переменнойц mythid индификатор главного thid'a 
	 a = a + 1;
	printf("thread %ld результат вычисления a=%d\n", mythid, a);
	pthread_join(thid, (void **)NULL);//ожидание завершения порожденного threada
	return 0;
}

