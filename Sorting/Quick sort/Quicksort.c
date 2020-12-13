#include<stdio.h>
int partition(int A[],int lb,int ub);
int  quicksort(int A[],int lb,int ub);
void main()
{
    int i,n;
    printf("Enter the number of elements...");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements in the list...\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    quicksort(A,0,n-1);
    printf("Sorted list...");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}
int quicksort(int A[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(A,lb,ub);
        quicksort(A,lb,loc-1);
        quicksort(A,loc+1,ub);
    }
}
int partition(int A[],int lb,int ub)
{
    int pivot,temp;
    pivot=A[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(A[start]<=pivot)
            start++;
        while(A[end]>pivot)
            end--;
        if(start<end)
        {
            temp=A[start];
            A[start]=A[end];
            A[end]=temp;
        }
    }
    temp=A[lb];
    A[lb]=A[end];
    A[end]=temp;
    return end;
}
