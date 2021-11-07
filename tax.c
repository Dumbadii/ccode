#include <stdio.h>

float single_tax(float income);
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);

int main()
{
    //
    printf("tax of 23350: %f\n", single_tax(23350));
    printf("tax of 257500: %f\n", single_tax(257500));

    int a[] = {2, -6, 3, 5, 1, -1};
    int b[] = {4, -2, -4, -5, -7, -3, 6, 7};
    int r[12];

    matrix_multiply(a, b, r, 3, 2, 4);
    for(int i=0;i<12;i++)
        printf(" %d", r[i]);
    printf("\n");

    return 0;
}

float single_tax(float income)
{
    static int range[5] = {0, 23350, 56550, 117950, 256500};
    static float rate[5] = {.15, .28, .31, .36, .396};

    float tax = 0;
    int i;

    for(i=1; i<5 && income > range[i]; i++) 
        tax += (range[i] - range[i-1]) * rate[i-1];

    tax += (income - range[i-1]) * rate[i-1];

    return tax;
}

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
    int row, col, rc, tmp;

    for(row=0; row<x; row++)
        for(col=0; col<z; col++)
        {
            tmp = 0;
            for(rc=0; rc<y; rc++)
                tmp += m1[row*y+rc] * m2[rc*z+col];
            r[row*z+col] = tmp;
        }
}