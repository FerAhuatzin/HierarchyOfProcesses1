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
	pid_t pidActual;
	pid_t pidPadre;
	
	//imprime id de R y de nada
	pidActual = getpid();
	pidPadre = getppid();
	printf("Hola soy R con id %d y soy el padre general\n", pidActual);
	pid = fork();
	
	//left branch
	if (pid==0) {
		//imprime id de T y de R
		pidActual = getpid();
		pidPadre = getppid();
		printf("Hola, soy T con id %d y mi padre es R con id %d\n", pidActual, pidPadre);
		pid = fork();
		if (pid==0) {
			//imprime id de V y de T
			pidActual = getpid();
			pidPadre = getppid();
			printf("Hola, soy V con id %d y mi padre es T con id %d\n", pidActual, pidPadre);
		} //end if
		else if (pid>0) {
		//end
		} //end if
	} //end if
	
	//right branch
	else if (pid>0) {
		pid = fork();
		if (pid==0) {
			//imprime id de W y de R
			pidActual = getpid();
			pidPadre = getppid();
			printf("Hola, soy W con id %d y mi padre es R con id %d\n", pidActual, pidPadre);
			pid = fork();
			if (pid==0) {
				//imprime id de S y de W
				pidActual = getpid();
				pidPadre = getppid();
				printf("Hola, soy S con id %d y mi padre es W con id %d\n", pidActual, pidPadre);
			} //end if
			else if (pid>0) {
				pid = fork();
				if (pid == 0) {
					//imprime id de L y de W
					pidActual = getpid();
					pidPadre = getppid();
					printf("Hola, soy L con id %d y mi padre es W con id %d\n", pidActual, pidPadre);
					pid = fork();
					if (pid == 0) {
						//imprime id de P y de L
						pidActual = getpid();
						pidPadre = getppid();
						printf("Hola, soy P con id %d y mi padre es L con id %d\n", pidActual, pidPadre);
					} //end if
					else if (pid>0) {
						//end
					} //end if
				} //end if
				else if (pid>0) {
					//end
				} //end if
			} //end if
		} //end if
		else if (pid>0) {
		//end
		} //end if
	} //end if
	return 0;
} //end main
