#include <cstdio>
#include <memory.h>
#include <algorithm>

int n,m,c[201],d[201],f[21][850],path[21][850],sel[20],prese,def;

void getpath(int x,int y)
{
	if(x==0) return;
	int i=path[x][y];
	prese+=c[i];
	def+=d[i];
	sel[x]=i;
	getpath(x-1,y+c[i]-d[i]);
}

bool find(int k,int j,int i)
{
	if(k==0) return false;
	if(path[k][j]==i) return true;
	find(k-1,j+c[path[k][j]]-d[path[k][j]],i);
}

int main()
{
	int _=0;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		_++;
		prese=0;def=0;
		memset(path,0,sizeof(path));
		memset(f,-1,sizeof(f));
		f[0][400]=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&c[i],&d[i]);
		for(int k=1;k<=m;k++)
			for(int j=0;j<=800;j++)
				if(~f[k-1][j])
					for(int i=1;i<=n;i++)
					{
						if(!find(k-1,j,i)&&f[k][j-c[i]+d[i]]<f[k-1][j]+c[i]+d[i])
						{
							f[k][j-c[i]+d[i]]=f[k-1][j]+c[i]+d[i];
							path[k][j-c[i]+d[i]]=i;
						}
					}
		int x,y;
		for(int i=0;i<=400;i++)
			if(f[m][400+i]>=0||f[m][400-i]>=0)
			{
				if(f[m][400+i]>f[m][400-i])
					y=400+i;
				else
					y=400-i;
				x=m;
				break;
			}
		getpath(x,y);
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",_,prese,def);
		std::sort(sel+1,sel+1+m);
		for(int i=1;i<=m;i++) printf(" %d",sel[i]);
		printf("\n\n");
	}
	
	return 0;
}