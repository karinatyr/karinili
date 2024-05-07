#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        int fd; 
        size_t size;
        char resstring[11];
//создаем символьный массив где будет зраниться имя файла fifo
        char name[] = "fifo.fifo";
	if ((fd = open(name, O_RDONLY)) <0) {
                        printf("не удалось открыть FIFO для чтения\n");
                        exit(-1);
	}
        size = read(fd, resstring, 11);
        if (size != 11){
		printf("не удалось прочитать информацию из fifo\n");
                exit(-1);
                }
        printf("Процесс fifo2  прочитал информацию: %s\n", resstring);
        if (close(fd) < 0){
                printf("не получилось закрыть FIFO, открытый на чтение\n");
                exit(-1);
     	}
        return 0;
}
