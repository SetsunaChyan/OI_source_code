#include <bits/stdc++.h>
using namespace std;

int n,s,vis[305];
struct node
{
    int a,b,d;
}p[305];

bool cmp(node x,node y)
{
    return x.b<y.b;
}

void solve()
{
    s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        vis[i]=0,scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].d);
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        int mx=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&p[j].a<=p[i].b) mx=max(mx,p[j].d);
        s+=mx;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&p[j].a<=p[i].b) vis[j]=1;
    }
    printf("%d\n",s);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
