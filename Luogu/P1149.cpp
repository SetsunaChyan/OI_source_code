#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <math.h>

int n,ans=0,t=10,ws[1145]={1,1,1,1,1,1,1,1,1,1},cost[1145]={6,2,5,5,4,5,6,3,7,6},num[1145]={0,1,2,3,4,5,6,7,8,9}; 

int swap(int a,int b)
{
	int t;
	t=cost[a];cost[a]=cost[b];cost[b]=t;
	t=num[a];num[a]=num[b];num[b]=t;
	return 0;
}

int quick_sort(int l,int r)
{
	if (l>=r) return 0;
	int x=num[r],i=l-1,j;
	for(j=l;j<=r-1;j++)
		if(num[j]<=x)
		{
			i++;
			swap(i,j);	
		}
	swap(i+1,j);
	int q=i+1;
	quick_sort(l,q-1);
	quick_sort(q+1,r);
	return 0;
}

int binary_find(int x)
{
	int l=0,r=t,m;
	while(r-l>=1)
	{
		m=(l+r)/2;
		if(num[m]==x) return m;
		else if(num[m]<x) l=m+1;
		else r=m;
	}
	return -1;
}

int find(int x)
{
	for(int i=0;i<t;i++)
		if(num[i]==x) return i;
	return -1;
}

int main()
{
	std::queue<int> que;
	scanf("%d",&n);
	n-=4;
	for(int i=0;i<10;i++) que.push(i);
	while(que.size())
	{
		int x=que.front();que.pop();
		for(int i=1;i<10;i++)
		{
			if(cost[i]+cost[x]<=n-6)
			{
				int pl=i*pow(10,ws[x]);
				ws[t]=ws[x]+1;
				cost[t]=cost[x]+cost[i];
				num[t]=pl+num[x];
				que.push(t);
				t++;
			}
		}
	}
	quick_sort(0,t-1);
	for(int i=0;i<t;i++)
		for(int j=0;j<t;j++)
		{
			int p=binary_find(num[i]+num[j]);
			if(p!=-1&&cost[p]+cost[i]+cost[j]==n) ans++;
		}
	printf("%d",ans);
	return 0;
}

