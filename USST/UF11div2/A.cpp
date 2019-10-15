#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int debug=100005;
int vis[debug],n,m,qaq[debug][105],s,k;
vector<int> e[debug],c[105];

void bfs(int typ)
{
    pii p;
    queue<pii> q;
    for(auto st:c[typ])
        q.emplace(st,0),vis[st]=typ,qaq[st][typ]=0;
    while(!q.empty())
    {
        p=q.front(),q.pop();
        for(auto to:e[p.first])
            if(vis[to]!=typ)
            {
                vis[to]=typ;
                qaq[to][typ]=min(qaq[to][typ],p.second+1);
                q.emplace(to,p.second+1);
            }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            qaq[i][j]=0x3f3f3f3f;
    for(int i=1,x;i<=n;i++)
        scanf("%d",&x),c[x].push_back(i);
    for(int i=0,u,v;i<m;i++)
        scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
    for(int i=1;i<=k;i++) bfs(i);
    for(int i=1;i<=n;i++)
    {
        sort(qaq[i]+1,qaq[i]+1+k);
        int sum=0;
        for(int j=1;j<=s;j++) sum+=qaq[i][j];
        printf("%d ",sum);
    }
    return 0;
}
