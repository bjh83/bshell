#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"list.h"

#define false 0
#define true 1

typedef int bool;

int execute(list_t* list) {
	printf("Execution begining\n");
	char* command = pop(&list);
	char** argv = malloc(len(list) * sizeof(char*));
	int index = 0;
	pid_t cpid;
	while(list != NULL) {
		argv[index++] = pop(&list);
	}

	cpid = fork();
	if(cpid == 0) { //True if is child process
		execv(command, argv); //Execute command
	} else {
		wait(); //Wait until child terminates
	}
}

