 #include<stdio.h>
 void mergesort(int A,int lb,int ub);
 void merge(int A[],int lb,int mid,int ub);
 void main()
 {
     int i,n;
     printf("Enter the number of elements...");
     scanf("%d",&n);
     int A[n];
     printf("Enter the elements in the list...\n");
     for(i=0;i<n;i++)
         scanf("%d",&A[i]);
     mergesort(A,0,n-1);
     printf("Sorted list...");
     for(i=0;i<n;i++)
         printf("%d ",A[i]);
 }
void mergesort(A,lb,ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(A,lb,mid);
        mergesort(A,mid+1,ub);
        merge(A,lb,mid,ub);
    }
}
void merge(int A[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int B[ub];
    while(i<=mid && j<=ub)
    {
        if(A[i]<=A[j])
        {
            B[k]=A[i];
            i++;
        }
        else
        {
            B[k]=A[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            B[k]=A[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            B[k]=A[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++)
        A[k]=B[k];
}
