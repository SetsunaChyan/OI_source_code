#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,fa[2005];
ll c[2005],k[2005],x[2005],y[2005];
struct edge
{
    ll v;
    int x,y;
    edge(){}
    edge(int x,int y,ll v):x(x),y(y),v(v){}
};
vector<edge> e;
vector<int> a1;
vector<pair<int,int>> a2;

inline bool cmp(edge a,edge b){return a.v<b.v;}

int _find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=_find(fa[x]);
}

void _merge(int x,int y)
{
    x=_find(x),y=_find(y);
    if(x!=y) fa[x]=y;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",x+i,y+i),fa[i]=i;
    for(int i=1;i<=n;i++)
        scanf("%lld",c+i);
    for(int i=1;i<=n;i++)
        scanf("%lld",k+i);
    for(int i=1;i<=n;i++)
    {
        e.emplace_back(0,i,c[i]);
        for(int j=i+1;j<=n;j++)
            e.emplace_back(i,j,(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]));
    }
    sort(e.begin(),e.end(),cmp);
    ll sum=0;
    for(auto p:e)
    {
        if(_find(p.x)!=_find(p.y))
        {
            sum+=p.v;
            _merge(p.x,p.y);
            if(p.x==0) a1.push_back(p.y);
            else a2.emplace_back(p.x,p.y);
        }
    }
    printf("%lld\n%d\n",sum,(int)a1.size());
    if(a1.size())
    {
        for(auto p:a1) printf("%d ",p);
        printf("\n");
    }
    printf("%d\n",(int)a2.size());
    for(auto p:a2) printf("%d %d\n",p.first,p.second);
    return 0;
}
