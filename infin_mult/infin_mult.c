#include <unistd.h>
#include <stdlib.h>

int fstrlen(char *s)
{
    int count = 0;
    while (*s++)
        count++;
    return count;
}

int fisdigit(int c)
{
    return c >= '0' && c <= '9';
}

void fputstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}

int value(int c)
{
    return c - '0';
}

int character(int val)
{
    return val >= 10 ? val - 10 + '0' : val + '0';
}

void print(char *res)
{
    int i = 0;
    while (res[i] && res[i] == '0')
        i++;
    fputstr(res + i);
}

void zero(char *s, int l)
{
    while (--l >= 0)
        s[l] = 0;
}

int iszero(char *s, int len)
{
    return *s == '0' && len == 1;
}

int add(int a, int b, int carry)
{
    return value(a) + value(b) + carry;
}

int s_adder(char *res, int idx, int carry)
{

    int n = res[idx] ? value(res[idx]) : 0;
    int val = n + carry;
    int c = character(val);
    res[idx] = c;
    return val >= 10 ? 1 : 0;
}

int multiply(int a, int b, int *carry)
{
    a = value(a), b = value(b);
    int sum = a * b + *carry;
    if (sum >= 10)
        *carry = sum / 10;
    else
        *carry = 0;;
    return sum % 10;
}

void shift(char *res, int rlen, int idx)
{
    int i = 0;
    while (idx < rlen)
        res[i++] = res[idx++];
}

char *adder(char *a, int alen, char *b, int blen)
{
    int rlen, carry, idx, val, aok, bok;
    rlen = 1 + (alen > blen ? alen : blen);
    char *res = malloc((rlen + 1) * sizeof(char));
    zero(res, rlen + 1);
    idx = rlen - 1;
    alen--; blen--;
    carry = 0;
    while (1)
    {
        aok = alen >= 0 && fisdigit(a[alen]);
        bok = blen >= 0 && fisdigit(b[blen]);
        if (aok || bok)
        {
            if (aok && bok)
            {
                val = add(a[alen--], b[blen--], carry);
                res[idx--] = character(val);
            }
            else if (aok)
            {
                val = value(a[alen--] + carry);
                res[idx--] = character(val);
            }
            else if (bok)
            {
                val = value(b[blen--] + carry);
                res[idx--] = character(val);
            }
            carry = val >= 10 ? 1 : 0;
        }
        else
            break ;
    }
    if (carry)
        res[idx] = '1';
    else
        idx++;
    if (idx)
        shift(res, rlen + 1, idx);
    return res;
}

void mult(char *a, int alen, char *b, int blen)
{
    int rlen, carry, c, pr, tmpi, tmpl, llen, alen_s, iter;
    rlen = 1;
    char *res = malloc(2 * sizeof(char));
    zero(res, 2); *res = '0';
    llen = alen > blen ? alen : blen;
    alen_s = alen; blen--;
    iter = 0;
    while (blen >= 0)
    {
        tmpl = llen + iter + 1;
        char *tmp = malloc((tmpl + 1) * sizeof(char));
        zero(tmp, tmpl + 1);
        tmpi = tmpl - iter - 1;
        c = b[blen--];
        carry = 0;
        alen = alen_s - 1;
        while (alen >= 0)
        {
            pr = multiply(a[alen--], c, &carry);
            tmp[tmpi--] = character(pr);
        }
        if (carry)
            tmp[tmpi] = character(carry);
        else
            tmpi++;
        if (tmpi)
            shift(tmp, tmpl + 1, tmpi);
        if (iter)
        {
            int i, j;
            j = tmpl - tmpi - iter;
            i = 0;
            while (i++ < iter)
                tmp[j++] = '0';
        }
        char *res_p = res;
        res = adder(res, rlen, tmp, tmpl - tmpi);
        rlen = fstrlen(res);
        free(res_p); free(tmp);
        iter++;
    }
    print(res);
    free(res);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char *a, *b;
        a = av[1], b = av[2];
        int alen, blen, aneg, bneg;
        alen = fstrlen(a), blen = fstrlen(b);
        aneg = *a == '-', bneg = *b == '-';
        if (iszero(a, alen) || iszero(b, blen))
            write(1, "0", 1);
        else
        {
            if ((aneg && !bneg) || (bneg && !aneg))
                write(1, "-", 1);
            mult(a + (aneg ? 1 : 0), alen - (aneg ? 1 : 0),
                 b + (bneg ? 1 : 0), blen - (bneg ? 1 : 0));
        }
    }
    write(1, "\n", 1);
}
