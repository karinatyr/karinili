#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// подключение библиотеки для управления файлами 
#include <fcntl.h>
int main(){
	int fd;//файловый дескриптер
 	size_t size;//размер строки в байтаз
        char string[18];
//открытие файла на чтение
        if ((fd=open("text1.txt", O_RDONLY))<0) {
                printf("Ошибка при открытии файла на чтении\n");
                exit(-1);
        }
//чтение из файла из файла
        size =read(fd, string, 18);
        //проверка кол-ва прочитанных байт
	if(size != 18){
                printf ("НЕ удалось прочитать всю строку из файла\n");
                exit(-1);
                }
//печать строки
        printf("%s\n", string);
//закрытие файла 
        if(close(fd)<0){
		printf ("не удалось открыть файл\n");
		exit(-1);
	}
	return 0;
	}
