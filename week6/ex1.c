#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int fd[2];
	if (pipe(fd) == -1) {
		return 0;
	}
	char first_string[] = "Pipe string!";
	char second_string[] = "";
	write(fd[1], first_string, strlen(first_string) + 1);
	close(fd[1]);
	read(fd[0], second_string, strlen(first_string) + 1);
	close(fd[0]);
	printf("Second string from pipe is: \"%s\"\n", second_string);
}
