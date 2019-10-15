#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,c,d,vis[45000];
vector<int> prime,ans;

void seive()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<45000;i++)
        if(!vis[i])
        {
            prime.push_back(i);
            for(int j=i<<1;j<45000;j+=i) vis[j]=1;
        }
}

int f(int x,int y)
{
    int ret=0;
    while(x%y==0) ret++,x/=y;
    return ret;
}

void check(int x)
{
    int ma=f(a,x),mb=f(b,x),mc=f(c,x),md=f(d,x);
    if(ma==mb&&mc==md&&md>=mb) ans.push_back(md-mb+1);
    else if(ma==mb&&mc<md&&md>=mb) ans.push_back(1);
    else if(mc==md&&ma>mb&&md>=mb) ans.push_back(1);
    else if(ma>mb&&mc<md&&md==mb) ans.push_back(1);
    else ans.push_back(0);
}

void solve()
{
    ans.clear();
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(d==1)
    {
        if(b==1&&c==1) printf("1\n"); else printf("0\n");
        return;
    }
    for(auto p:prime)
    {
        if(d%p==0) check(p);
        while(d%p==0) d/=p;
    }
    if(d!=1) check(d);
    int ret=1;
    for(auto p:ans) ret*=p;
    printf("%d\n",ret);
}

int main()
{
    int _;
    scanf("%d",&_);
    seive();
    while(_--) solve();
    return 0;
}
