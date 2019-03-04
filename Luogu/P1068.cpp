#include <stdio.h>

struct node
{
	int xh,score;
}a[5000];

void quick_sort(int l,int r)
{
	int i=l,j=r,m=a[(i+j)/2].score,mx=a[(i+j)/2].xh;
	node t;
	do
	{
		while(a[i].score>m||a[i].score==m&&a[i].xh<mx) i++;
		while(a[j].score<m||a[j].score==m&&a[j].xh>mx) j--;
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
	int n,m,i,t,pre=0,ans=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i].xh,&a[i].score);
	quick_sort(0,n-1);
	m=(float)m*1.5;
	for(i=0;i<n;i++)
	{
		m--;
		if(m<0)
			if(pre!=a[i].score) break;
		ans++;
		pre=a[i].score;
	}
	printf("%d %d\n",pre,ans);
	for(i=0;i<ans;i++)
		printf("%d %d\n",a[i].xh,a[i].score);
	return 0;
}
