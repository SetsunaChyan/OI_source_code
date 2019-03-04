#include<bits/stdc++.h>
using namespace std;
int f[120][120]={0};
int n,m;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[120][120];

int isearch(int x,int y)
{
    int nx,ny;
    if(f[x][y]!=1) return f[x][y];
    int b=0;
    for(int i=0;i<4;i++)
    {
            nx=x+d[i][0];
            ny=y+d[i][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]<a[x][y]) b=max(isearch(nx,ny)+1,b);
    }
    f[x][y]=max(f[x][y],b);
    return f[x][y];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            f[i][j]=1;
        }
    }
    int imax=-1;
    int tem;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tem=isearch(i,j);
            if(tem>imax) imax=tem;
        }
    }
    cout<<imax<<endl;
    return 0;
}