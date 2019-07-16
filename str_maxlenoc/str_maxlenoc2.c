maxlen(char *res, char *s)
{
    char *
    start = -1;
    while (*res && *s)
    {
        if (*res == *s)
        {
            if (start == -1)
                start = res;
        }
        res++;
        s++;
        if (end != -1)
            end++;
    }
}
int main(int ac, char **av)
{
    if (ac > 1)
    {
        char *res = av[1];
        int i = 2;
        while (i < ac)
        {
            maxlen(res, av[i]);
            if ()
            {

            }
            i++;
        }
        fputstr(res);
    }
}