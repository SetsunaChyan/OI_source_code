#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,deg[105],vis[105],st;
vector<pii> e[105];
vector<int> ans;

void dfs(int now,pii eid)
{
    int to,id;
    for(auto p:e[now])
    {
        to=p.first,id=p.second;
        if(vis[abs(id)]) continue;
        vis[abs(id)]=1;
        dfs(to,p);
    }
    ans.push_back(eid.second);
}

int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].emplace_back(y,i),e[y].emplace_back(x,-i);
        deg[x]++,deg[y]++,st=x;
    }
    int cnt=0;
    for(int i=0;i<=6;i++) if(deg[i]&1) cnt++,st=i;
    if(cnt>2) return printf("No solution"),0;
    dfs(st,{0,0});
    if(ans.size()!=n+1) return printf("No solution"),0;
    for(int i=n-1;i>=0;i--)
        printf("%d %c\n",abs(ans[i]),"+-"[ans[i]<0]);
    return 0;
}
