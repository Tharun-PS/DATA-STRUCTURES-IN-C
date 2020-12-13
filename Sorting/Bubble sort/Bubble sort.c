#include<stdio.h>
int main()
{
    int n,i,j,t;
    printf("Enter the number of elements in the array...");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements...\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j+1]<a[j])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("The sorted array...\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
