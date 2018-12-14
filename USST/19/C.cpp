#include <cstdio>
#include <memory.h>

int f[201][6],n,m;

int g(int x,int y)
{
    if(f[x][y]) return f[x][y];
    if(x==0||y==1) return f[x][y]=1;
    if(x<y) return f[x][y]=g(x,x);
    else return f[x][y]=g(x,y-1)+g(x-y,y);
}

int main()
{
    memset(f,0,sizeof(f));
    scanf("%d%d",&n,&m);
    n-=m;
    g(n,m);
    printf("%d",f[n][m]);

    return 0;
}
