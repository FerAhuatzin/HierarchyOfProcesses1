#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main () {
	pid_t pid;
	int fd;
	int n;
	int m;
	int element1;
	int element2;
	int result;
	int array1[] = {2,4,6,8,10,12,14,16,18,20};
	int array2[] = {1,3,5,7,9,11,13,15,17,19};
	
	pid = fork();
	if (pid == 0) {
		fd = creat("N.txt",777);
		n = write(fd,array1,sizeof(array1));	
	} //end if
	if (pid > 0) {
		pid =  fork();
		if (pid==0) {
			fd = creat("M.txt",777);
			n = write(fd,array2,sizeof(array2));	
		} //end if
		if (pid>0) {
			int fdN = open("N.txt", 0);
			int fdM = open("M.txt", 0);
			for (int i = 0; i<10; i++) {
				m = read(fdN, &element1, sizeof(int));
				printf("m de N: %d\n", m);
				close(fd);
				m = read(fdM, &element2, sizeof(int));
				printf("m de M: %d\n", m);
				close(fd);
				result = element1+element2;
				printf("%d + %d = %d \n", element1,element2,result);
			} //end for
		} //end if
	} //end if
	
	
} //end main
