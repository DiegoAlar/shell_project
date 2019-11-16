#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char **split_line(char *line);
void forking(char **splitted);
int main (void)
{
      	char *line = NULL;
	char *ex = "Exit\n";
	char *com = "l";
	int i = 0, m = 0;
	char **splitted = NULL;
	size_t bufsize = 0;

	while (1)
	{
		printf("$ ");
		getline(&line, &bufsize, stdin);
		if (strcmp(line, ex) == 0)
		{
			free(line);
			return (0);
		}
		splitted = split_line(line);
		printf("%s\n", splitted[0]);
		if (strcmp(splitted[0], com) == 0)
		{
			printf("Entro\n");
			while (m < 5)
			{
				forking(splitted);
				m++;
			}
		}
		free(splitted);
		free(line);
		line = NULL;
	}



}
char **split_line(char *line)
{

	int bufsize = LSH_TOK_BUFSIZE, position = 0;
      	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

    	if (!tokens)
	{
		perror("Alloc Error\n");
		exit(98);

	}
    	token = strtok(line, LSH_TOK_DELIM);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				perror("Allocation error\n");
				exit(99);
			}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
void forking(char **splitted)
{
	pid_t child;
	int status;
	char *arr[] = {"/bin/ls", "-l", NULL};

	printf("before");
	child = fork();
	if (child == 0)
	{
		printf("iji");
		execve(arr[0], arr, NULL);
		sleep(1);
	}
	else
	{
		wait(&status);


	}

}

