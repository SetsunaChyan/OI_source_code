#include <bits/stdc++.h>
using namespace std;

int n,m,fa[200005],mx=-1,num,vis[200005];
vector<int> q,e[200005],dis;

void dfs(int now,int pa,int dep)
{
    fa[now]=pa;
    if(vis[now]&&dep>mx) mx=dep,num=now;
    for(auto to:e[now])
        if(to!=pa) dfs(to,now,dep+1);
}

void check(int now,int pa,int dep)
{
    if(vis[now]) dis.push_back(dep);
    for(auto to:e[now])
        if(to!=pa) check(to,now,dep+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=0,x;i<m;i++)
    {
        scanf("%d",&x);
        q.push_back(x);
        vis[x]=1;
    }
    dfs(q[0],0,0);
    if(mx&1) return printf("NO"),0;
    mx/=2;
    for(int i=0;i<mx;i++) num=fa[num];
    check(num,0,0);
    if(max_element(dis.begin(),dis.end())==min_element(dis.begin(),dis.end())) printf("YES\n%d",num);
    else printf("NO");
    return 0;
}
