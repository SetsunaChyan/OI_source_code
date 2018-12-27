#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
int n,q[1000050],head=0,ed=1;
ll dp[1000050],ans=0;
struct node
{
    ll x,y,a;
}p[1000050];

inline bool cmp(node a,node b){return a.x<b.x;}
inline ll max(ll a,ll b){return a>b?a:b;}
inline double Y(int x){return dp[x];}
inline double X(int x){return p[x].x;}
inline double rate(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].a);
    sort(p+1,p+n+1,cmp);
    p[0].a=p[0].x=p[0].y=0;
    q[0]=0;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        while(head<ed-1&&rate(q[head],q[head+1])>p[i].y) head++;
        dp[i]=dp[q[head]]-p[i].a+p[i].y*(p[i].x-p[q[head]].x);
        ans=max(ans,dp[i]);
        while(head<ed-1&&rate(q[ed-2],q[ed-1])<rate(q[ed-1],i)) ed--;
        q[ed++]=i;
    }
    printf("%lld",ans);
    return 0;
}