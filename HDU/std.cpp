#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bit1[1000005],bit2[1000005],ans=0,tmp=0;
int n,a[1000005],t[1000005];

int _find(int x)
{
    return lower_bound(t+1,t+n+1,x)-t;
}

void add(ll bit[],int x,ll y){for(;x<=n;x+=x&-x) bit[x]+=y;}
ll sum(ll bit[],int x){ll ret=0; for(;x;x-=x&-x) ret+=bit[x]; return ret;}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),t[i]=a[i];
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++)
        a[i]=_find(a[i]);
    for(int i=n;i;i--)
    {
        tmp+=sum(bit1,a[i]-1)*i;
        add(bit1,a[i],1);
        add(bit2,a[i],i);
    }
    for(int i=n;i;i--)
    {
        ans+=tmp;
        tmp-=sum(bit2,n)-sum(bit2,a[i]);
        add(bit2,a[i],-i);
    }
    printf("%lld",ans);
    return 0;
}
