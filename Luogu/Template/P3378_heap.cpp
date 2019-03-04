#include <stdio.h>
#define MAX_N 1000000

int heap[MAX_N],size=0; 

void push(int x)
{
	int i=size++;
	while(i>0)
	{
		int p=(i-1)/2;
		if(heap[p]<=x) break;
		heap[i]=heap[p];
		i=p;
	}
	heap[i]=x;
}

int pop()
{
	int ret=heap[0];
	int i=0;
	int x=heap[--size];
	while(i*2+1<size)
	{
		int a=i*2+1,b=i*2+2;
		if(b<size&&heap[b]<heap[a])a=b;
		if(x<=heap[a]) break;
		heap[i]=heap[a];
		i=a;
	}
	heap[i]=x;
	return ret;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int c,x;
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				printf("%d\n",heap[0]);
				break;
			case 3:
				pop();
				break;
		}
	}
	return 0;
}
