#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*addchar(char *s, char c)
{
	char	*res;
	int		i;
	int		len;

	//printf("adding chr %c to string [%s]", c, s);
    len = ft_strlen((char *)s);
	i = 0;
	res = (char *)malloc(sizeof(char) *(len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[len] = c;
		i++;
	res[len + 1] = '\0';
	return (res);
}

void print_bytes(int c)
{
    int i;
    int x;

    i = 7;
    printf("%c\t", c);
   //printf("bytes of char %c\n", c);
    while (i >= 0)
    {
        x = c >> i;
        //printf("desplazo %c[%d] de %d ; x = %c[%d]", c, c, i, x, x);
        if (x % 2 == 0)
            //printf("byte n %d ; 0\n", 8 - i);
            printf("0");
        else
            //printf("byte n %d ; 1\n", 8 - i);
            printf("1");
        i--;
    }
    printf("\n");
}

void sig_handler(int sig)
{
    static int c = 0;
    static unsigned int i = 0;
    static char *str = "";

    c <<= 1;
    if (sig == SIGUSR1)
    {
        c |= 0;
      //  printf("recived byte 0[%i]\n", i);
      //  print_bytes(c);
    }
    else
    {
        c |= 1;
       // printf("recived byte 1[%i]\n", i);
       // print_bytes(c);
    }
    i++;
    if (i == 8)
    {
        //printf("char = %c\n", c);
        str = addchar(str, c);
        if (c == '\0')
        {
            printf("***string is : %s\n", str);
            free(str);
            str = "";
        }
        i = 0;
        c = 0;
    }
    //printf("char is : %i", c);
    //print_bytes(c);
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
