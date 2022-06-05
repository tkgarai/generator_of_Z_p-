#include <stdio.h>

int sqr_mlt(int, int, int);

void main()
{
    int i, x, e, p;
    printf("enter a prime p: ");
    scanf("%d", &p);
    printf("the generators of Z_p* are: ");
    for (x = 2; (x < p); x++)
    {
            for (e = 2; e < p; e++)
                if (sqr_mlt(x, e, p) == 1)
                {
                    if(e == p-1)
                        printf("    %d    ", x);
                    break;
                }
    }
}
int sqr_mlt(int x, int e, int n)//returns 1 if the value is 1, otherwise returns 0
{
    int bin[100] = {0}, i, v;
    // convert e from binary to decimal
    // in bin[], i've stored the binary form of e in backwards
    for (i = 0; e > 0; i++)
    {
        if (e & 1)
            bin[i] = 1;
        e = e >> 1;
    }
    // starting the square and multiply algo
    v = x;
    // ignoring the first bit of e since intial value of v is taken as x
    for (i = i - 2; i >= 0; i--)
    {
        v = (v * v) % n;
        if (bin[i])
            v = (v * x) % n;
    }
    if (v == 1)
        return 1;
    else
        return 0;
}
