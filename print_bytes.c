#include <stdio.h>

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

void str2bytes(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        print_bytes(str[i++]);
}
/*
int main(int ac, char **av)
{
    int i;
    
    i = 0;
    while (av[1][i])
    {
        print_bytes(av[1][i]);
        i++;
    }
    //print_bytes(c);
    return (0);
}*/