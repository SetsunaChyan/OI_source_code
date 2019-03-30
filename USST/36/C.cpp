#include <cstdio>

int n,m,p[100][100];

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&p[i][j]);
		printf("%d",p[0][0]);
		for(int i=1;i<m;i++)
			printf(" %d",p[0][i]);
		for(int i=1;i<n;i++)
		{
			if(i&1)
				for(int j=m-1;j>=0;j--)
					printf(" %d",p[i][j]);
			else
				for(int j=0;j<m;j++)
					printf(" %d",p[i][j]);
		}
		if(_) printf("\n");
	}
	return 0;
}
