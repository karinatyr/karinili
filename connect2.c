#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){
	int fd;
 	size_t size;
        char string[17];
        if ((fd=open("text1.txt", O_RDONLY))<0) {
                printf("Ошибка при открытии файла на чтении\n");
                exit(-1);
        }

        size =read(fd, string, 17);
        if(size != 17){
                printf ("НЕ удалось прочитать всю строку из файла\n");
                exit(-1);
                }
        printf("%s\n", string);
        if(close(fd)<0){
		printf ("не удалось открыть файл\n");
		exit(-1);
	}
	return 0;
	}
