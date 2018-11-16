#include <cstdio>

const int move[5][2]={0,0,1,0,-1,0,0,-1,0,1};
int mp[5][5],a[5][5];
inline int min(int a,int b){return a<b?a:b;}

inline void re()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			a[i][j]=mp[i][j];
}

inline void change(int x,int y)
{
	for(int i=0;i<5;i++)
	{
		int dx=x+move[i][0],dy=y+move[i][1];
		if(dx>=0&&dx<5&&dy>=0&&dy<5) a[dx][dy]^=1;
	}
}

inline bool check()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(!a[i][j]) return false;
	return true;
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		int ans=25;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				scanf("%1d",&mp[i][j]);
		for(int i=0;i<(1<<5);i++)
		{
			int q=0,g=i,p=0;
			re();
			while(g)
			{
				if(g&1) {change(0,p);q++;}
				g>>=1;p++;
			}
			for(int j=1;j<5;j++)
				for(int k=0;k<5;k++)
					if(!a[j-1][k]) {change(j,k);q++;}
			if(check()) ans=min(ans,q);
		}
		if(ans>6)
			printf("-1\n");
		else 
			printf("%d\n",ans);
	}
	return 0;
}