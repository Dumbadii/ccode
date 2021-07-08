#include <stdio.h>

int invert(int x, int p ,int n);

int main(void)
{
    int x, p, n;

    printf("enter x p n:\n");
    scanf("%d %d %d", &x, &p, &n);

    printf("result of invert is: %d\n", invert(x,p,n));

    return 0;
}

int invert(int x, int p, int n)
{
    int r;
    
    r = ~(~0 << (p + n - 1) | ~(~0 << (p -1)));
    return x ^ r;
}