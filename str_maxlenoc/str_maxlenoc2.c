#include <stdlib.h>
#include <unistd.h>

typedef struct s_pos
{
    char *s;
    int n;
} t_pos;

int fstrlen(char *s)
{
    int n = 0;
    while (*s++)
        n++;
    return n;
}

char *fstrsub(char *s, int n)
{
    char *res = malloc((n + 1) * sizeof(char));
    char *p = res;
    while (n-- > 0)
        *res++ = *s++;
    *res = 0;
    return p;
}

void fputstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}

t_pos maxlen(char *res, char *s)
{
    t_pos ret;
    int n;
    char *p, *ss, *ress;
    ss = s;
    ret.n = 0;
    while (*res)
    {
        ress = res;
        s = ss;
        while (*s)
        {
            if (*s == *res)
            {
                n = 0;
                p = res;
                while (*s == *res)
                {
                    s++;
                    res++;
                    n++;
                }
                if (n > ret.n)
                {
                    ret.s = p;
                    ret.n = n;
                    res -= 1;
                }
                else
                    res = ress;
            }
            else
                s++;
        }
        res++;
    }
    return ret;
}

#include <stdio.h>
int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i, d, mx;
        char *res, s;
        res = av[1];
        mx = fstrlen(res);
        i = 2;
        while (i < ac)
        {
            t_pos ret = maxlen(res, av[i]);
            if (ret.n < mx)
            {
                res = fstrsub(ret.s, ret.n);
                mx = ret.n;
                if (!mx)
                    break;
            }
            i++;
        }
        fputstr(res);
    }
    fputstr("\n");
}