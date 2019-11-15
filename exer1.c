#include <stdio.h>
#include <unistd.h>

/**
   * main - PID
    *
     * Return: Always 0.
      */
int main(int ac, char **av)
{
	int i = 0;
	while (av[i])
	{
		printf("command n. %d: %s\n", (i + 1), av[i]);
		i++;
	}

		        return (0);
}
