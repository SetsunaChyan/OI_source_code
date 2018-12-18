#include <cstdio>
#include <memory.h>

int f[10005],t[6]={1,2,3,5,10,20};

int main()
{
	memset(f,0,sizeof(f));
	f[0]=1;
	for(int i=0;i<6;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++)
			for(int w=10000;w>=t[i];w--)
				if(f[w-t[i]]) f[w]=1;
	}
	int ans=0;
	for(int i=1;i<=10000;i++)
		ans+=f[i];
	printf("%d",ans);
	return 0;
}
