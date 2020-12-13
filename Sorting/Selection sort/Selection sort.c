#include<stdio.h>
int main()
{
    int n,i,j,min,t;
    printf("Enter the number ofelements in the array...");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements...\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    min=a[0];
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                min=j;
            }
        }

        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
    printf("The sorted array...\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
