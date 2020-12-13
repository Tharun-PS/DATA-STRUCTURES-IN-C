#include<stdio.h>
void create(int []);
void da(int [],int);
int main()
{
	int heap[30],n,i,l,c;
    printf("Enter no. of elements:");
	scanf("%d",&n);
    printf("\nEnter elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&heap[i]);
	heap[0]=n;
	create(heap);
	while(heap[0] > 1)
	{
		l=heap[0];
		c=heap[1];
		heap[1]=heap[l];
		heap[l]=c;
		heap[0]--;
		da(heap,1);
	}
	printf("\nArray after sorting:\n");
	for(i=1;i<=n;i++)
		printf("%d ",heap[i]);
    return 0;
}
void create(int heap[])
{
	int i,n;
	n=heap[0];
    for(i=n/2;i>=1;i--)
		da(heap,i);
}
void da(int heap[],int i)
{
	int j,c,n,flag=1;
	n=heap[0];
    while(2*i<=n && flag==1)
	{
		j=2*i;
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else
		{
			c=heap[i];
			heap[i]=heap[j];
			heap[j]=c;
			i=j;
		}
	}
}
