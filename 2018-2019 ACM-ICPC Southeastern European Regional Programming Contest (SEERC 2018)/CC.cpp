#include <bits/stdc++.h>
using namespace std;

int n,m,col[105],dis[105][105];
vector<int> e[105];

void dfs(int now,int fa,int st,int dep)
{
    dis[st][now]=dep;
    for(auto to:e[now])
        if(to!=fa) dfs(to,now,st,dep+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",col+i);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++) dfs(i,i,i,0);
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            if(col[i]+col[j]<2) continue;
            int cur=0;
            for(int k=1;k<=n;k++)
                if(col[k]&&max(dis[i][k],dis[j][k])<=dis[i][j]) cur++;
            if(cur>=m) ans=min(ans,dis[i][j]);
        }
    printf("%d",ans);
    return 0;
}

/*
6 3
1 1 0 1 1 1
1 2
1 3
1 4
3 5
3 6

9 4
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9
*/
