#include <bits/stdc++.h>
using namespace std;

char s[20][20][20];
int fa[20*20*20],x,y,n,m,k;

int f(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=f(fa[x]);
}

void me(int x1,int y1,int z1,int x2,int y2,int z2)
{
    if(s[x1][y1][z1]=='#') return;
    if(s[x2][y2][z2]=='#') return;
    int a=x1*n*m+y1*m+z1;
    int b=x2*n*m+y2*m+z2;
    if(f(a)!=f(b)) fa[f(a)]=f(b);
}

int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=0;i<n*m*k;i++) fa[i]=i;
    for(int i=0;i<k;i++)
        for(int j=0;j<n;j++)
            scanf("%s",s[i][j]);
    scanf("%d%d",&x,&y);
    x--;y--;
    for(int j=0;j<n;j++)
        for(int l=0;l<m;l++)
            for(int i=0;i<k;i++)
            {
                if(i) me(i,j,l,i-1,j,l);
                if(j) me(i,j,l,i,j-1,l);
                if(l) me(i,j,l,i,j,l-1);
                if(i<k-1) me(i,j,l,i+1,j,l);
                if(j<n-1) me(i,j,l,i,j+1,l);
                if(l<m-1) me(i,j,l,i,j,l+1);
            }
    int ans=0;
    for(int i=0;i<n*m*k;i++)
        if(f(i)==f(x*m+y)) ans++;
    printf("%d",ans);
    return 0;
}
