#include <cstdio>

int tot=0,q[1005],end=0,n,m;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	scanf("%d%d",&m,&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		int flag=0;
		for(int i=max(0,end-m);i<end;i++)
			if(q[i]==x) {flag=1;break;}
		if(!flag)
		{
			tot++;
			q[end++]=x;
		}
	}
	printf("%d",tot);
	return 0;
}