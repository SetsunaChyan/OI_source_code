#include <bits/stdc++.h>
using namespace std;

int T;
int cnt,n,head[21],tot,vis[21];
float p;
struct edge
{
	int to,nxt;
}e[405];

void add_edge(int x,int y)
{
	e[tot].nxt=head[x];	
	e[tot].to=y;
	head[x]=tot++;
}

void gen()
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			float rp=rand()/(double)RAND_MAX;
			//printf("debug %f %f\n",rp,p);
			if(rp<=p)
			{
				add_edge(i,j);
				add_edge(j,i); 
			}
		}
}

bool check()
{
	int ck=1;
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int g=q.front();
		q.pop();
		for(int i=head[g];~i;i=e[i].nxt)
		{
			if(vis[e[i].to]) continue;
			vis[e[i].to]=1;
			ck++;
			q.push(e[i].to);
		}
	}
	//printf("d %d\n",ck==n);
	return ck==n;
}

void solve()
{
	T=(13-n/2)*1000;
	cnt=0;
	for(int i=0;i<T;i++)
	{
		memset(head,-1,sizeof(head));
		tot=0;
		gen();
		if(check()) cnt++;
	}
	printf("%.6f\n",((double)cnt)/(T-1));
}

int main()
{
	while(~scanf("%d%f",&n,&p)) solve();
	return 0;
}
