#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct job
{
    char id;
    int dead;
    int profit;
}job;

int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

int comparison(const void* a, const void* b)
{
    job* temp1 = (job*)a;
    job* temp2 = (job*)b;
    // if(temp1->profit>temp2->profit)
    // {
    //     return temp1->profit;
    // }
    // return temp2->profit;
    return (temp2->profit - temp1->profit);
}


void JobScheduling(job arr[],int n)
{
    qsort(arr,n,sizeof(job),comparison);
    int res[n];
    bool slot[n];
    for(int i=0;i<n;i++)
    {
        slot[i]=false;
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j=min(n, arr[i].dead)-1; j >= 0; j--) 
        {
            if (slot[j] == false) 
            {
                res[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    printf("result of Job scheduling code is:-");
    for(int i=0;i<n;i++)
    {
        if(slot[i]==true)
        {
            // cout<<arr[res[i]].id<<" ";
            printf("%c ",arr[res[i]].id);
        }
    }
    printf("\n");
}

int main(void)
{
    job arr[]=
    {
        { 'a', 2, 100},
        { 'b', 1, 19 },
        { 'c', 2, 27 },
        { 'd', 1, 25 },
        { 'e', 3, 15 }
    };
    int n=sizeof(arr)/sizeof(arr[0]);
    JobScheduling(arr,n);
}