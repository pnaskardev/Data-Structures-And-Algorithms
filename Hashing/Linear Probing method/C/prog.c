#include<stdio.h>
#define SIZE 10
void insert(int H[],int key);
int hash(int key);
int probe(int H[],int key);
int search(int H[],int key);
int main(void)
{
    int HT[10]={0};
    insert(HT,12);
    insert(HT,25);
    insert(HT,35);
    insert(HT,26);
    printf("Key found at:-%d\n",search(HT,35));
}

void insert(int H[],int key)
{
    int index=hash(key);
    if(H[index]!=0)
    {
        index=probe(H,key);
    }
    H[index]=key;
}
int hash(int key)
{
    return key%SIZE;
}
int probe(int H[],int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i)%SIZE;
}
int search(int H[],int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key)
    {
        i++;
    }
    return (index+i)%SIZE;
}