#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){

	pid_t childpid = 0;
	int i, n, opt;

	/* Option that allows the user to designate how many processes to run at once */
	while (opt != -1){
		opt = (getopt(argc, argv, "n:h:p"));
		switch(opt)
		{
			case 'n':
				n = atoi(optarg);
				break;
			case 'h':
				puts("Executing ass1 requires two arguments: the -n argument, and a number to follow to show the limit for amount of processes. An example execution would be: ./ass1 -n 5");
				return 0;
			case 'p':
				perror(argv[0]);
				break;
			case '?':
				errno = 8;
				perror("Executing ass1 requires two arguments: the -n argument, and a number to follow to show the limit for amount of processes. An example execution would be: ./ass1 -n 5");
				return 0;
			default:
				break;
		}
	}

	// if (argc != 3){
	// 	errno = 22; //invalid arguments
	// 	perror("Error: Invalid arguments, try using the format runsim -n 5");
		
	// 	return 1;
	// }

	// if (argc != 2) {
	// 	fprintf(stderr, "Usage: %s processes\n", argv[0]);
	// 	return 1;
	// }
	// n = atoi(argv[1]);
	for(i = 1; i < n; i++){
		if ((childpid = fork())){
			break;
		}
	}

	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);

	return 0;

}