#include<cstdio>
#include<iostream>

using namespace std;

#define LENGTH 10

void mergesort2(int,int);
void merge2(int,int,int);

int S[LENGTH] = {27,10,12,20,25,13,15,22,1,33};
int U[LENGTH];

int main(void)
{
    int i;
    mergesort2(0,LENGTH-1);
    for(i=0;i<LENGTH;i++)
        printf("%d ",S[i]);
    printf("\n");
}

void mergesort2(int low, int high)
{
    if(low<high)
    {
        int mid;
        mid = (low+high)/2;
        mergesort2(low,mid);
        mergesort2(mid+1,high);
        merge2(low,mid,high);
    }
}

void merge2(int low, int mid, int high)
{
    int i=low,j=mid+1,k=low;

    while(i<=mid && j<=high)
    {
        if(S[i]<S[j])
        {
            U[k++]=S[i];
            i++;
        }
        else
        {
            U[k++]=S[j];
            j++;
        }
    }
    if(i>mid)
        for(;j<high;j++)
            U[k++]=S[j];
    else
        for(;i<mid;i++)
            U[k++]=S[i];
    for(i=low;i<high;i++)
        S[i] = U[i];
}

