#include <bits/stdc++.h>
using namespace std;
int n,flag=1,x[1005],y[1005],r[1005],vis[1005],ax,ay;
vector<int> e[1005];

inline int dis2(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

void dfs(int now,int col)
{
    vis[now]=col==2?1:2;
    for(auto to:e[now])
    {
        if(vis[to])
        {
            if(vis[to]==vis[now]) flag=0;
            continue;
        }
        dfs(to,vis[now]);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",x+i,y+i,r+i);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(dis2(i,j)==(r[i]+r[j])*(r[i]+r[j]))
                e[i].push_back(j),e[j].push_back(i);
    ax=r[0],ay=r[n-1];
    dfs(0,1);
    if(flag&&vis[n-1])
    {
        if(vis[0]!=vis[n-1]) printf("-");
        printf("%d:%d",ax/__gcd(ax,ay),ay/__gcd(ax,ay));
    }
    else
        printf("The input gear cannot move.");
    return 0;
}

/*
16
10 10 5
20 10 5
30 10 5
40 10 5
10 20 5
20 20 5
30 20 5
40 20 5
10 30 5
20 30 5
30 30 5
40 30 5
10 40 5
20 40 5
30 40 5
40 40 5
*/
