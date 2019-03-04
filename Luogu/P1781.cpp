#include <stdio.h>
#include <string.h>

struct node
{
	int num,len;
	char p[101];
}a[20];

int s(node *a,node *b)
{
	int i;
	if(a->len>b->len) return 1;
	if(a->len<b->len) return 0;
	for(i=0;i<a->len;i++)
	{
		if(a->p[i]>b->p[i]) return 1;
		if(a->p[i]<b->p[i]) return 0;	
	}
	return 0;
}

void quick_sort(int l,int r)
{
	int i=l,j=r;
	node t,m=a[(i+j)/2];
	do
	{
		while(s(&a[i],&m)) i++;
		while(s(&m,&a[j])) j--;
		if(i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}while(i<=j);
	if(i<r) quick_sort(i,r);
	if(l<j) quick_sort(l,j);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i].p);
		a[i].len=strlen(a[i].p);
		a[i].num=i+1;
	}
	quick_sort(0,n-1);
	printf("%d\n%s",a[0].num,a[0].p);
	return 0;
}

