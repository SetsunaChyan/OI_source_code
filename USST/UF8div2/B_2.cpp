#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll s[100005],ans,qaq[100005];
vector<int> e[100005];

void chk(int now,int fa,ll mx)
{
    if(s[now]!=-1&&s[now]<mx)
    {
        ans=-1;
        return;
    }
    ll nmx=mx;
    if(s[now]!=-1) nmx=s[now];
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        chk(to,now,nmx);
        if(ans==-1) return;
    }
}

ll dfs(int now,int fa)
{
    ll nmx=0x3f3f3f3f3f3f3f3fll;
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        nmx=min(nmx,dfs(to,now));
    }
    if(s[now]==-1)
    {
        for(auto &to:e[now])
        {
            if(to==fa) continue;
            ans+=qaq[to]-nmx;
        }
        return qaq[now]=nmx;
    }
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        ans+=qaq[to]-s[now];
    }
    return qaq[now]=s[now];
}

int main()
{
    scanf("%d",&n);
    for(int i=2,x;i<=n;i++)
        scanf("%d",&x),e[i].push_back(x),e[x].push_back(i);
    e[0].push_back(1);
    for(int i=1;i<=n;i++)
        scanf("%lld",s+i);
    chk(1,1,0);
    if(ans==-1) return printf("-1"),0;
    dfs(0,0);
    printf("%lld",ans);
    return 0;
}

/*
8
1 1 2 2 3 3 4
5 6 6 10 7 6 9 12

5
1 2 2 3
1 -1 2 3 -1

4
1 2 2
0 -1 8 7
*/
