#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t child1, child2;

    child1 = fork();

    if(child1 == 0)
    {
        // First child
        printf("First Child\n");
        printf("PID = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }

    else
    {
        child2 = fork();

        if(child2 == 0)
        {
            // Second child
            printf("Second Child\n");
            printf("PID = %d\n", getpid());
            printf("PPID = %d\n", getppid());
        }

        else
        {
            // Parent
            printf("Parent Process\n");
            printf("Parent PID = %d\n", getpid());
            printf("Child1 PID = %d\n", child1);
            printf("Child2 PID = %d\n", child2);
        }
    }

    return 0;
}