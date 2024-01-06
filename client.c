#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void str2bytes(char *str);

void send_sig(int pid, unsigned char c)
{
    int i;
    unsigned char bit;

    //bit = c;
    i = 7;
    while (i >= 0)
    {
        bit = c >> i;
        if (bit %2 == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i--;
        usleep(42);
    }
}

int main(int ac, char **av)
{
    int pid;
    int i;
    
    if (ac != 3)
    {
        return (0);
    }
    i = 0; 
    str2bytes(av[2]);
    while (av[2][i] != 0)
    {
        send_sig(pid, av[2][i]);
        i++;
    }
    return (0);
}