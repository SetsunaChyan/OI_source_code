#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cst[100005],fa[100005],n,k,m;
map<string,int> mp;
char s[30];
ll ans=0;

int _find(int x){return x==fa[x]?x:fa[x]=_find(fa[x]);}
void _merge(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x!=y) fa[x]=y,cst[y]=min(cst[x],cst[y]);
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s),mp[string(s)]=i;;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cst[i]=x;
        fa[i]=i;
    }
    for(int i=0;i<k;i++)
    {
        int y,fst,x;
        scanf("%d%d",&y,&fst);
        for(int j=1;j<y;j++)
            scanf("%d",&x),_merge(x,fst);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%s",s);
        ans+=cst[_find(mp[string(s)])];
    }
    printf("%lld",ans);
    return 0;
}
