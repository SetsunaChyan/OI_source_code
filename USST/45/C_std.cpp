#include <bits/stdc++.h>
using namespace std;

const int mv[4][2]={1,0,0,1,-1,0,0,-1};
int white,black,m,n,x,vis[500005],flag=1;

void dfs(int x,int y)
{
    vis[x*m+y]=1;
    if((x+y)&1) black++; else white++;
    for(int i=0;i<4;i++)
    {
        int dx=x+mv[i][0];
        int dy=y+mv[i][1];
        if(dx>=0&&dx<n&&dy>=0&&dy<m&&!vis[dx*m+dy]) dfs(dx,dy);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&vis[m*i+j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!vis[m*i+j])
            {
                white=0,black=0,dfs(i,j);
                flag&=(black==white);
            }
    if(flag) printf("Yes"); else printf("No");
    return 0;
}