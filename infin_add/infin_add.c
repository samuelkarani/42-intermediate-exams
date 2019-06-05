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

int value(int c)
{
    return c - '0';
}

int add(int a, int b)
{
    return value(a) + value(b);
}

int bigger(char *a, int alen, char *b, int blen, int *equal)
{
    if (alen == blen)
    {
        while (*a == *b)
        {
            a++;
            b++;
        }
        *equal = *a == *b;
        return *a > *b;
    }
    *equal = 0;
    return alen > blen;
}

void print(char *res, int len)
{
    int i = 0;
    if (*res == '-')
        write(1, res++, 1);
    while (i < len && res[i] == '0')
        i++;
    if (i == len)
        write(1, "0", 1);
    else
        write(1, res + i, len - i);
}

int sub(int a, int b, int *borrow, int pb)
{
    a = value(a);
    b = value(b);
    if (a < b)
    {
        a += 10;
        *borrow = 1;
    }
    else
        *borrow = pb ? 1 : 0;
    return a - b;
}

int character(int val)
{
    return val >= 10 ? val - 10 + '0' : val + '0';
}

void subtract(char *a, int alen, char *b, int blen)
{
    int rlen, idx, val, aok, bok, borrow, pb;
    rlen = alen > blen ? alen : blen;
    char res[rlen];
    idx = rlen - 1;
    alen--; blen--;
    borrow = pb = 0;
    while (1)
    {
        aok = alen >= 0 && fisdigit(a[alen]);
        bok = blen >= 0 && fisdigit(b[blen]);
        if (aok || bok)
        {
            if (borrow)
            {
                if (a[alen] == '0')
                {
                    a[alen] = '9';
                    pb = 1;
                }
                else
                {
                    a[alen]--;
                    borrow = 0;
                }
            }
            if (aok && bok)
            {
                val = sub(a[alen--], b[blen--], &borrow, pb);
                res[idx--] = character(val);
            }
            else if (aok)
                res[idx--] = a[alen--];
            pb = 0;
        }
        else
            break ;
    }
    if (*a == '-')
        res[idx] = '-';
    else
        idx++;
    print(res + idx, rlen - idx);
}


void adder(char *a, int alen, char *b, int blen)
{
    int rlen, carry, idx, val, aok, bok, negs;
    negs = *a == '-' && *b == '-';
    rlen = 1 + alen > blen ? alen : blen + negs;
    char res[rlen];
    carry = 0;
    idx = rlen - 1;
    alen--; blen--;
    while (1)
    {
        aok = alen >= 0 && fisdigit(a[alen]);
        bok = blen >= 0 && fisdigit(b[blen]);
        if (aok || bok)
        {
            if (aok && bok)
            {
                val = add(a[alen--], b[blen--]);
                res[idx--] = character(carry + val);
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
        res[idx--] = '1';
    if (negs)
        res[idx] = '-';
    else
        idx++;
    print(res + idx, rlen - idx);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char *a, *b;
        a = av[1], b = av[2];
        int alen, blen, aneg, bneg, equal;
        alen = fstrlen(a), blen = fstrlen(b);
        aneg = a[0] == '-', bneg = b[0] == '-';
        if ((aneg && bneg) || (!aneg && !bneg))
            adder(a, alen, b, blen);
        else
        {
            equal = 0;
            if (bigger(a + (aneg ? 1 : 0), alen - (aneg ? 1 : 0),
                       b + (bneg ? 1 : 0), blen - (bneg ? 1 : 0), &equal))
                subtract(a, alen, b, blen);
            else if (!equal)
                subtract(b, blen, a, alen);
            else
                write(1, "0", 1);
        }
    }
    write(1, "\n", 1);
}