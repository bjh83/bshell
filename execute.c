#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"list.h"

#define false 0
#define true 1

typedef int bool;

int execute(list_t* list) {
	char* command = list->value;
	char** argv = malloc(len(list) * sizeof(char*));
	int index = 0;
	pid_t cpid;
	while(list != NULL) {
		char* value = pop(&list);
		argv[index++] = value;
		printf("%s\n", value);
	}

	printf("Command: %s\n", command);
	cpid = fork();
	if(cpid == 0) { //True if is child process
		execv(command, argv); //Execute command
	} else {
		wait(); //Wait until child terminates
	}
}

