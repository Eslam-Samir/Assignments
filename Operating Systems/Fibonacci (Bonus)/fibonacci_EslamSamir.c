#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printFibSequence(int x);

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage: ./fibonacci <sequence>\n");
		return 1;
	}
	int number = atoi(argv[1]);
	if(number <= 0)
	{
		printf("Error: please enter a non-negative number\n");
		return 2;
	}
	else
	{
	    int i, n;
	    for(i = 0, n = strlen(argv[1]); i < n; i++)
	    {
	        if(!isdigit(argv[1][i]))
	        {
	            printf("Error: please enter a positive integer number\n");
	            return 3;
	        }
	    }
	}
	
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		printf("Forking Failed\n");
	    return 3;
	}
	if(pid == 0)
	{
		printFibSequence(number);
	}
	else
	{
		wait(NULL);
	}
	return 0;
}

void printFibSequence(int x)
{
	if(x == 1)
	{
		printf("fib[0] = 0\n");
	}
	else if(x > 1)
	{
	    printf("fib[0] = 0\n");
		printf("fib[1] = 1\n");
	    int prev1 = 1, prev2 = 0, result, i;
		for(i = 2; i < x; i++)
		{
		    result = prev2 + prev1;
		    printf("fib[%d] = %d\n", i, result);
		    prev2 = prev1;
		    prev1 = result;
		}
	}
}
