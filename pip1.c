#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int fd[2];
	size_t size;
	char string[]="Hello, world!";
	char resstring[14];
	/*Попытаеимя создать pipe*/
	if (pipe(fd) <0) {
	/*Если создать pipe не удалось, печатаем об этом сообщение
 и прекращаем работу*/
		printf("Can\'t create pipe\n");
		exit(-1);
	}


	/*Попробуем записать в pipe 14 байт в другой массив, т.е. всю записанную строку*/
	size =write(fd[1], string, 14);
	if(size != 14){
	/*Если записалось меньшее количество байт, сообщаем об ошибке*/
		printf ("CAn\'t write all string\n");
		exit(-1);
		}
	/*Попробуем прочитать из pip'a 14 байт в другой 
масисв, т.е. всю записанную строку */
	size = read(fd[0], resstring, 14);
	if(size<0){
		/*Если прочитать не смогли, сообщаем об ошибке*/
		printf ("Can\'t read string\n");
		exit(-1);
	}
	/*Печатаем прочитанную строку*/
	printf("%s\n", resstring);
	/*Закрываем входной поток*/
	if(close(fd[0])<0){
		printf ("Can\'t close input stream\n");
	}
	if (close(fd[1])<0){
		printf ("Can\'t close output stream\n");
	}
	return 0;
	}
