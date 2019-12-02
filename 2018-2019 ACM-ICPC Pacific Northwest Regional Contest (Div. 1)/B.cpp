#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e7+5;
bool vis[N];
int u[N],p[N],cnt;
ll ans=0,l1,r1,l2,r2;

void init()
{
    u[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
            u[i]=-1,p[cnt++]=i;
        for(int j=0;j<cnt&&i*p[j]<N;j++)
        {
            vis[i*p[j]]=1;
            if(i%p[j]) u[i*p[j]]=-u[i];
            else
            {
                u[i*p[j]]=0;
                break;
            }
        }
    }
}

void cal(int sg,ll x,ll y)
{
    for(int i=1;i<=min(x,y);i++)
        ans+=sg*u[i]*(x/i)*(y/i);
}

int main()
{
    init();
    scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
    cal(1,r1,r2);
    cal(-1,l1-1,r2);
    cal(-1,r1,l2-1);
    cal(1,l1-1,l2-1);
    printf("%lld",ans);
    return 0;
}
