#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

struct node
{
    int v,pos;
}e[200005];
const int mod=998244353;
int n,a[200005];
long long ans=1;

inline bool cmp(node a,node b){return a.v<b.v||a.v==b.v&&a.pos<b.pos;}

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&e[i].v);
        e[i].pos=i;
    }
    sort(e,e+n,cmp);
    a[e[0].pos]++;
    for(int i=1;i<n;i++)
        if(e[i].v!=e[i-1].v)
        {
            a[e[i].pos]++;
            a[e[i-1].pos+1]--;
        }
    a[e[n-1].pos+1]--;
    int k=0;
    for(int i=0;i<=n;i++)
    {
        k+=a[i];
        if(k==0) ans=ans*2%mod;
    }
    printf("%lld",ans);
    return 0;
}