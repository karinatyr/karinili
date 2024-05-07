#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fd, result; 
	size_t size;
	char resstring[13];
//создаем символьный массив где будет зраниться имя файла fifo
	char name[] = "fifo.fifo";
//после первого запуска программы необходимо заккоментировать процесс создания файла fifo
/*	if (mknod(name, S_IFIFO | 0666, 0) <0){
		printf("Не удалось создать файл FIFO\n");
		exit(-1);
	}
*/
	//поорждаем дочерний процесс
	if ((result = fork()) <0){
		printf("Не удалось создать дочерний процесс\n");
		exit(-1);
	}
	//процесс-родитлель пишет информацию в fifo
	else if(result > 0){
		if ((fd = open(name, O_WRONLY)) < 0) {
			printf("Не удалось открыть файл на запись\n");
			exit(-1);
	}
		size = write(fd, "Hello, child", 13);
		if (size != 13){
			printf("Не получилось записать 13 байт в FIFO\n");
			exit(-1);
		}

		if (close(fd)<0){
			printf("Не получилось закрыть FIFO\n");
			exit(-1);
		}

		printf("Процесс-родитель записал информацию в FIFO и завершил работу\n");
	
	}
// процесс ребенок читает информацию из fifo
	else {
		if ((fd = open(name, O_RDONLY)) <0) {
			printf("не удалось открыть FIFO для чтения\n");
			exit(-1);
	}
		size = read(fd, resstring, 13);
		if (size != 13){
			printf("не удалось прочитать информацию из fifo\n");
			exit(-1);
		}

		printf("Процесс-ребенок прочитал информацию: %s\n", resstring);
		if (close(fd) < 0){
			printf("не получилось закрыть FIFO, открытый на чтение\n");
			exit(-1);
	}
	}
	return 0;
}
