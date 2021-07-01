#include <stdio.h>

#define N 10

int split(int a[], int low, int high);
void quickSort(int a[], int low, int high);

int main()
{
    int a[N], i;

    printf("Enter %d numbers to be sorted:\n", N);
    for(i=0;i<N;i++)
    {
        scanf("%d", &a[i]);
    }

    quickSort(a,0,N-1);

    printf("In sorted order:\n");
    for(int i=0;i<N;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int a[], int low, int high)
{
    int middle;
    
    if (low >= high) return;
    middle = split(a, low, high);
    quickSort(a, low, middle-1);
    quickSort(a, middle+1, high);
}

int split(int a[], int low, int high)
{
    int part_element = a[low];

    for(;;) 
    {
        while (low < high && part_element <= a[high])
            high--;
        if(low >= high) break;
        a[low++] = a[high];

        while(low < high && a[low] <= part_element)
            low++;
        if(low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}