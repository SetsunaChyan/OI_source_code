#include <cstdio>
#include <memory.h>

int n,l[5];
unsigned int f[31][30][29][28][27];

int main()
{
	while(scanf("%d",&n)&&n)
	{
		memset(l,0,sizeof(l));
		f[0][0][0][0][0]=1;
		for(int i=0;i<n;i++) scanf("%d",&l[i]);
		for(int a=1;a<=l[0];a++)
			for(int b=0;b<=l[1]&&b<=a;b++)
				for(int c=0;c<=l[2]&&c<=b;c++)
					for(int d=0;d<=l[3]&&d<=c;d++)
						for(int e=0;e<=l[4]&&e<=d;e++)
						{
							f[a][b][c][d][e]=f[a-1][b][c][d][e];
							if(b) f[a][b][c][d][e]+=f[a][b-1][c][d][e];
							if(c) f[a][b][c][d][e]+=f[a][b][c-1][d][e];
							if(d) f[a][b][c][d][e]+=f[a][b][c][d-1][e];
							if(e) f[a][b][c][d][e]+=f[a][b][c][d][e-1];
						}
		printf("%u\n",f[l[0]][l[1]][l[2]][l[3]][l[4]]);
	}
	return 0;
}