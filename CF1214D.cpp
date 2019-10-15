#include <bits/stdc++.h>
using namespace std;

const int mv[4][2]={-1,0,0,-1,0,1,1,0};
int n,m,mx,cut,num;
vector<char> mp[10000005];
vector<int> dfn[10000005],low[10000005];
char s[10000005];

int dfs(int x,int y)
{
    if(x==n-1&&y==m-1)
    {
        mp[x][y]='0';
        return 1;
    }
    for(int i=2;i<4;i++)
    {
        int dx=x+mv[i][0],dy=y+mv[i][1];
        if(dx<0||dx>=n||dy<0||dy>=m||mp[dx][dy]=='#') continue;
        if(mp[dx][dy]=='0')
        {
            mp[x][y]='0';
            continue;
        }
        if(dfs(dx,dy)) mp[x][y]='0';
    }
    if(mp[x][y]=='.') mp[x][y]='#';
    return mp[x][y]=='0';
}

void tarjan(int x,int y)
{
    dfn[x][y]=low[x][y]=++num;
    int flag=0;
    for(int i=0;i<4;i++)
    {
        int dx=x+mv[i][0],dy=y+mv[i][1];
        if(dx<0||dx>=n||dy<0||dy>=m||mp[dx][dy]!='0') continue;
        if(!dfn[dx][dy])
        {
            tarjan(dx,dy);
            low[x][y]=min(low[x][y],low[dx][dy]);
            if(low[dx][dy]>=dfn[x][y])
            {
                flag++;
                if(x!=0||y!=0) cut++;
            }
        }
        else low[x][y]=min(low[x][y],dfn[dx][dy]);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++)
            dfn[i].push_back(0),mp[i].push_back(s[j]),low[i].push_back(0);
    }
    dfs(0,0);
    mp[0][0]='0';
    tarjan(0,0);
    /*printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%c",mp[i][j]);
        printf("\n");
    }*/

    if(!dfn[n-1][m-1])
        printf("0");
    else if(cut)
        printf("1");
    else
        printf("2");
    return 0;
}
