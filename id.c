//Подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Главная функция программы 
int main () {
	uid_t userid;
	gid_t groupid;
//Сисиемный вызов getuid()
	userid = getuid();
//Системныц вызов getgid()
	groupid = getgid();
	printf("Ид. пользователя: %d\n", userid);
//Возврат значения "о" из главной функции 
	printf("Ид. группы пользователя: %d\n", groupid);
	return 0;
}
