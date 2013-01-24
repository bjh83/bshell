#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"list.h"

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

	cpid = fork();
	if(cpid == -1) {
		printf("ERROR, fork failed!!!\n");
	} else if(cpid == 0) { //True if is child process
		printf("Child process begining\n");
		execv(command, argv); //Execute command
	} else {
		int i;
		for(i = 0; i < index; i++) {
			free(argv[i]);
		}
		free(argv);
		wait(); //Wait until child terminates
		printf("Execution terminated\n");
	}
}

