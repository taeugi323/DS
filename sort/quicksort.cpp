#include<cstdio>
using namespace std;

#define LENGTH 10

int *quicksort(int*, int, int);
int partition(int*, int, int);

int main(void)
{
    int a[LENGTH]={3,1,2,6,4,9,5,7,8,10};

    quicksort(a,0,LENGTH);
    for(int i=0;i<LENGTH;i++)
        printf("%d ",a[i]);

    printf("\n");
    return 0;

}

int *quicksort(int *a, int low, int high)
{
    int pivot;
    if(low < high)
    {
        pivot = partition(a,low,high);
        quicksort(a, low, pivot);
        quicksort(a, pivot+1, high);
    }
    return a;
}

int partition(int *a, int low, int high)
{
    int i,j,key,temp;
    key = a[low];   
    j = low;
    for(i=low+1;i<high;i++)
    {
        if(a[i] < key)
        {
            j++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    a[low] = a[j];
    a[j] = key;

    return j;

}
