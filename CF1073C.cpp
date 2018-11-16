#include <cstdio>

int zx=0,zy=0,nx=0,ny=0,n,dx,dy;
char s[200050];

inline int f(int x){return x<0?-x:x;}

int main()
{
	scanf("%d%s%d%d",&n,s,&dx,&dy);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U') {ny++;zy++;}
		else if(s[i]=='D') {ny--;zy++;}
		else if(s[i]=='L') {nx--;zx++;}
		else {nx++;zx++;}
	}
	if(zx<f(nx)||zy<f(ny)||f(nx-zx)%2||f(ny-zy)%2)
		printf("-1");
	else
		printf("%d",f((nx-zx)/2)+f((ny-zy)/2));
	return 0;
}