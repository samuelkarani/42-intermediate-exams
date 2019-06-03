#include <stdio.h>

int fislower(int c)
{
    return c >= 'a' && c <= 'z';
}

int fisupper(int c)
{
    return c >= 'A' && c <= 'Z';
}

int fisalpha(int c)
{
    return fislower(c) || fisupper(c);
}

int fstrlen(char *s)
{
    int n = 0;
    while (*s++)
        n++;
    return n;
}

void    flower(char *s)
{
    while (*s)
    {
        if (fisupper(*s))
            *s += 32;
        s++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *s = av[1];
        flower(s);
        int l = fstrlen(s);
        char c;
        int i, n;
        i = n = 0;
        while (i < l)
        {
            if (fisalpha(c = s[i]))
            {
                int si = i;
                int count = 0;
                while (i < l)
                {
                    if (s[i] == c)
                    {
                        count++;
                        s[i] = 0;
                    }
                    i++;
                }
                i = si;
                if (n)
                    printf(", ");
                printf("%d%c", count, c);
                n++;
            }
            i++;
        }
    }
    printf("\n");
}