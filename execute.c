#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"list.h"

int execute(list_t* list) {
	int length = len(list) + 1;
	char* command = pop(&list);
	char** argv = malloc(length * sizeof(char*));
	int index = length - 1;
	pid_t cpid;
	argv[index--] = NULL;
	while(list != NULL) {
		char* value = pop(&list);
		argv[index--] = value;
	}
	argv[index] = command;
	cpid = fork();
	if(cpid == -1) {
		printf("ERROR, fork failed!!!\n");
	} else if(cpid == 0) { //True if is child process
		printf("Child process begining\n");
		execv(command, argv); //Execute command
	} else {
		int i;
		for(i = 0; i < length - 1; i++) {
			free(argv[i]);
		}
		free(argv);
		wait(); //Wait until child terminates
	}
	return 1;
}

