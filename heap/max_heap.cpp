#include<cstdio>
#include<vector>
#include<climits>
using namespace std;

void swap(int*,int*);

int main()
{
    int menu,i;
    vector<int> pq;
    pq.push_back(INT_MAX);

    while(1)
    {
        printf("\n----------\n");
        printf("Input - 1\nPop - 2\nprint - 3\nquit - 4  ");
        scanf("%d",&menu);

        if (menu == 1)
        {
            int value;
            printf("What's your value? ");
            scanf("%d",&value);
            pq.push_back(value);
            i = pq.size()-1;
            while(pq[i] > pq[i/2])
            {
                swap(&pq[i],&pq[i/2]);
                i /= 2;
            }
        }
        else if(menu == 2)
        {
            // It adjusts from the root to proper leaf node by swapping
            // Then, the leaf node will have the max value
            int value, len_pq = pq.size()-1;
            i = 1;
            while(i*2 <= len_pq)
            {
                if(i*2 == len_pq)
                {
                    swap(&pq[i],&pq[i*2]);
                    i *= 2;
                }
                else
                {
                    if(pq[i*2]>pq[i*2+1])
                    {
                        swap(&pq[i],&pq[i*2]);
                        i *= 2;
                    }
                    else
                    {
                        swap(&pq[i],&pq[i*2+1]);
                        i = i*2+1;
                    }
                }
            }
            // i is smaller or equal than len_pq
            swap(&pq[len_pq],&pq[i]);   // Swap(the last node, the leaf node)
            value = pq[len_pq];
            pq.pop_back();
            
            // After above swapping, it may not be a heap. Adjust!
            if(i < len_pq)
            {
                while(pq[i] > pq[i/2])
                {
                    swap(&pq[i],&pq[i/2]);
                    i /= 2;
                }
            }

            printf("The value is %d\n",value);
        }
        else if(menu == 3)
        {
            if(pq.size() != 1)
                for(i=1;i<pq.size();i++)
                    printf("%d ",pq[i]);
            else
                printf("The heap is empty!\n");

        }

        else if(menu == 4)
            break;
    }

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
