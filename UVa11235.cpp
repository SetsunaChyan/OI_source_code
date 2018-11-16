#include <cstdio>

const int MAXN=100005;
int ST[MAXN][20],n,m,a[MAXN],cnt,head[MAXN],tail[MAXN],map[MAXN],time[MAXN];

inline int max(int a,int b)
{
	return a>b?a:b;
}

void initial()
{
	for(int i=0;i<n;i++)
		ST[i][0]=time[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;(1<<j)+i-1<n;i++)
			ST[i][j]=max(ST[i][j-1],ST[i+(1<<j-1)][j-1]);
}

int rmq(int l,int r)
{
	if(r<l) return 0;
	int k=0;
	while((1<<(k+1))<=r-l+1) k++;
	return max(ST[l][k],ST[r-(1<<k)+1][k]);
}

int main()
{
	while(scanf("%d",&n),n)
	{
		cnt=0;
		scanf("%d",&m);
		scanf("%d",&a[0]);
		head[0]=a[0];map[0]=0;time[0]=1;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]!=a[i-1])
			{
				tail[cnt]=i-1;
				cnt++;
				head[cnt]=i;
				time[i]=1;
			}
			else
				time[i]=time[i-1]+1;
			map[i]=cnt;
		} 
		map[n]=cnt+1;
		head[cnt+1]=n;
		initial();
		for(int i=0;i<m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			l--;r--;
			if(map[l]==map[r])
				printf("%d\n",r-l+1);
			else
				printf("%d\n",max(head[map[l]+1]-l,max(rmq(tail[map[l]]+1,head[map[r]]-1),r-head[map[r]]+1)));
		}
	}
	return 0;
}