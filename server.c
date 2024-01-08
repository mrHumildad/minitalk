#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("recived byte 0\n");
    }
    else
        printf("recived byte 1\n");
}

int main(void)
{
    printf("PID : %i\n", getpid());
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    usleep(42);
    while (1)
		pause();
}