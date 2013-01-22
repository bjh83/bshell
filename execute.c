#include<string.h>
#include<unistd.h>

#define false 0
#define true 1

typedef int bool;

int prog_call(char* prog_name, char* argv) {
	pid_t cpid;

	cpid = fork();

	if(cpid == 0) { //True if is child process
		execl(prog_name, argv);
	} else {
		wait();
	}
}

int execute(char* instruct) {
	int index;
	char* next_instruct = instruct;
	char* prog_name;
	char* argv;
	bool prog_name_found = false;
	for(index = 0; next_instruct[index] != '\0'; index++) {
		if(!prog_name_found && next_instruct[index] == ' ') {
			prog_name = malloc(index + 1);
			strncpy(prog_name, next_instruct, index);
			next_instruct += index + 1;
			index = 0;
		}
	}
	argc = malloc(strlen(next_instruct));
	strcpy(argv, next_instruct);
	int ret_val = call_prog(prog_name, argv);
	free(instruct);
	free(prog_name);
	free(argv);
	return ret_val;
}

