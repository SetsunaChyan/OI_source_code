#include<bits/stdc++.h>

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int n,m,x1=116,x2=0;
int y3=116,y2=0;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char c;
			do{scanf("%c",&c);}while(c!='W'&&c!='B');
			if(c=='B')
			{
				x1=min(j,x1);
				x2=max(j,x2);
				y3=min(i,y3);
				y2=max(i,y2);
			}
		}
	printf("%d %d\n",(y2+y3)/2,(x2+x1)/2);
	return 0;
}