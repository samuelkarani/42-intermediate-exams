int    count_of_2(int n)
{
    int i, count;
    if (n <= 0)
        return 0;
    i = count = 0;
    while (i < n)
    {
        int j = i;
        while (j)
        {
            if (j % 10 == 2)
                count++;
            j /= 10;
        }
        i++;
    }
    return count;
}

#include <stdio.h>
int main()
{
    printf("%d\n", count_of_2(25));
}