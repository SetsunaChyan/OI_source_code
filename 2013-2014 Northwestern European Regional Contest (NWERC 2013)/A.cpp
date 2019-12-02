#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,fa[2005];
int mp[2005][2005];
int _find(int x)
{
    if(fa[x]!=x) fa[x]=_find(fa[x]);
    return fa[x];
}
void _merge(int x,int y)
{
    x=_find(x),y=_find(y);
    if(x!=y) fa[x]=y;
}

int illa=-1,illb=-1,MIN=0x3f3f3f3f;
typedef pair<int,pair<int,int>> piii;
priority_queue<piii,vector<piii>,greater<piii>> q;
vector<int> e[2005],val[2005];

int dfs(int from,int f,int now,int dis)
{
    if(mp[from][now]!=dis)
    {
        if(mp[from][now]<MIN)
        {
            MIN=mp[from][now];
            illa=from;
            illb=now;
        }
    }
    for(int i=0;i<e[now].size();++i)
    {
        int to=e[now][i];
        if(to==f) continue;
        int V=val[now][i];
        dfs(from,now,to,dis+V);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;++i) fa[i]=i,e[i].clear(),val[i].clear();
        illa=-1,illb=-1,MIN=0x3f3f3f3f;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                scanf("%d",&mp[i][j]);
                if(i==j) continue;
                q.push(make_pair(mp[i][j],make_pair(i,j)));
            }
        int a,b,c;
        while(!q.empty())
        {
            piii t=q.top();q.pop();
            if(_find(t.second.first)==_find(t.second.second)) continue;
            printf("%d %d %d\n",t.second.first,t.second.second,t.first);
            a=t.first,b=t.second.first,c=t.second.second;
            e[b].push_back(c);
            e[c].push_back(b);
            val[b].push_back(a);
            val[c].push_back(a);
            _merge(t.second.first,t.second.second);
        }
        for(int i=1;i<=n;++i)
            dfs(i,i,i,0);
        if(illa==-1&&illb==-1) printf("%d %d %d\n",b,c,a);
        else printf("%d %d %d\n",illa,illb,MIN);
        puts("");
    }
    return 0;
}
