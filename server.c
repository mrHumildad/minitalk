#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("recived byte 0");
    }
    else
        printf("recived byte 1");
}

int main(void)
{
    printf("PID : %i\n", getpid());
    return (0);

    while (1)
		pause();
}