#include <stdio.h>

#define N 4 

void selectionSort(int a[], int length);
void maxToLast(int a[], int length);

int main()
{
    int a[N], i;

    printf("Enter %d numbers to be sorted:\n", N);
    for(i=0;i<N;i++)
        scanf("%d", &a[i]);

    selectionSort(a,N);

    printf("numbers in sorted order:\n");
    for(i=0;i<N;i++)
        printf("%d ", a[i]);
    
    return 0;
}

void selectionSort(int a[], int length)
{
    if(length < 2) return;
    maxToLast(a, length);
    selectionSort(a, --length);
}

void maxToLast(int a[], int length)
{
    int max = a[length-1];
    for (int i=0;i<length-1;i++)
    {
        if(max<a[i]) 
        {
            max=a[i];
            a[i]=a[length-1];
            a[length-1] = max;
        }
    }
}