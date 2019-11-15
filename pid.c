#include <stdio.h>
#include <unistd.h>

/**
   * main - PID
    *
     * Return: Always 0.
      */
int main(void)
{
	    pid_t my_pid, my_pid2;

	        my_pid = getpid();
 my_pid2 = getppid();

		    printf("%u\n", my_pid);

		    printf("%u\n", my_pid2);
			printf("%u\n", PID_MAX_LIMIT);
		        return (0);
}
