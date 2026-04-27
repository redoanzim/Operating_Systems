#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
    }

    else if(pid == 0)
    {
        // Child process
        for(int i=6; i<=10; i++)
        {
            printf("%d ", i);
        }
    }

    else
    {
        // Parent process
        for(int i=1; i<=5; i++)
        {
            printf("%d ", i);
        }
    }

    return 0;
}