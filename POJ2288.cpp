#include <cstdio>
#include <memory.h>

int f[1<<13][13][13],a[13][13],n,m,pv[13];
long long cnt[1<<13][13][13];
inline int max(int a,int b){return a>b?a:b;}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		memset(f,-1,sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",&pv[i]);
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			a[x][y]=a[y][x]=1;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(a[i][j])
				{
					f[(1<<i)+(1<<j)][i][j]=pv[i]+pv[j]+pv[i]*pv[j];
					cnt[(1<<i)+(1<<j)][i][j]=1;
				}
		for(int i=1;i<1<<n;i++)
			for(int j=0;j<n;j++) if(i>>j&1)
				for(int k=0;k<n;k++) if((i^1<<j)>>k&1&&a[j][k])
					for(int l=0;l<n;l++) if(((i^(1<<j)^(1<<k))>>l)&1) if(a[k][l]&&f[i^1<<j][k][l]>0)
					{
						int s=f[i^1<<j][k][l]+pv[j]+pv[j]*pv[k];
						if(a[j][l]) s+=pv[j]*pv[k]*pv[l];
						//printf("%d %d %d %d %d\n",i,j,k,l,s);
						if(f[i][j][k]==s)
							cnt[i][j][k]+=cnt[i^(1<<j)][k][l];
						else if(f[i][j][k]<s)
						{
							f[i][j][k]=s;
							cnt[i][j][k]=cnt[i^(1<<j)][k][l];
						}
					}
		int ans=-1;
		long long c=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ans=max(f[(1<<n)-1][i][j],ans);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(f[(1<<n)-1][i][j]==ans)
					c+=cnt[(1<<n)-1][i][j];
		if(n==1)
			printf("%d 1\n",pv[0]);
		else if(ans<0)
			printf("0 0\n");
		else
			printf("%d %lld\n",ans,c/2);
	}
	return 0;
}

/*
5
5 6
1 1 1 1 1 
1 2
1 3 
2 3 
3 4
3 5
4 5
4 3
1 1 1 1
1 2
2 3
3 4
4 6
1 1 1 1
1 2
1 3
1 4
2 3
2 4
3 4
3 3
1 2 3
1 2
2 3
1 3
4 3
1 1 1 1
1 4
2 4
3 4
*/