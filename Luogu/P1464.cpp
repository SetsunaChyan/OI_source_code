#include <stdio.h>

long long x,y,z; 
long long a[21][21][21];

long long w(long long x,long long y,long long z)
{
	if(x<=0||y<=0||z<=0) return 1;
	if(x>20||y>20||z>20) return w(20,20,20);
	if(a[x-1][y][z]==-1) a[x-1][y][z]=w(x-1,y,z);
	if(a[x-1][y-1][z]==-1) a[x-1][y-1][z]=w(x-1,y-1,z);
	if(a[x-1][y][z-1]==-1) a[x-1][y][z-1]=w(x-1,y,z-1);
	if(a[x-1][y-1][z-1]==-1) a[x-1][y-1][z-1]=w(x-1,y-1,z-1);
	return a[x-1][y][z]+a[x-1][y-1][z]+a[x-1][y][z-1]-a[x-1][y-1][z-1];
}

int main()
{
	int i,j,k;
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			for(k=0;k<21;k++)
				a[i][j][k]=-1;
	do
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x==-1&&y==-1&&z==-1) break;
		printf("w(%lld, %lld, %lld) = %lld\n",x,y,z,w(x,y,z));
	}while(1);	
	return 0;
} 
