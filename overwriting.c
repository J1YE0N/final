#include <sys/ptrace.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int ret, ret2, pid, len;
	unsigned addr;

	//pid set from argv
	pid = atoi(argv[1]);
	//printf("%d\n", pid); //confirm pid

	//make word array(using argv[2]'s length)
	char word[strlen(argv[2])];

	//copy user's string to word array
	strcpy(word, argv[2]);

	//attach(connect)
	ptrace(PTRACE_ATTACH, pid, 0, 0);
	
	addr = strtoul(argv[3], NULL, 16);

	//increase byte(char -1byte), input each character
	//using ptrace_poketext func.
	for( int i=0; i<strlen(argv[2]); i++ ){
		ptrace(PTRACE_POKETEXT, pid, addr+i, word[i]);
	}
	
	//detach ptrace debuger
	ptrace(PTRACE_DETACH, pid, 0, 0);
}


