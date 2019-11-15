#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char **split_line(char *line);

int main (void)
{
      	char *line = NULL;
	char *ex = "Exit\n";
	int i = 0;
	char **splitted = NULL;
	size_t bufsize = 0;

	while (1)
	{
		printf("$ ");
		getline(&line, &bufsize, stdin);
		if (strcmp(line, ex) == 0)
			return (0);
		splitted = split_line(line);
		free(splitted);
		free(line);
		line = NULL;
	}
	/*while (splitted[i])

  	  {

	  printf("%s\n", splitted[i]);

	  i++;


	  }*/


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

