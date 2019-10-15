#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,bit[70005],tmp[70005],a[70005];
ll ans;

void add(int x)
{
    for(;x<=n;x+=x&-x) bit[x]++;
}

int sum(int x)
{
   int ret=0;
   for(;x;x-=x&-x) ret+=bit[x];
   return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i),tmp[i]=a[i];
    sort(tmp,tmp+n);
    for(int i=0;i<n;i++) a[i]=lower_bound(tmp,tmp+n,a[i])-tmp+1;
    for(int i=n-1;i>=0;i--)
        ans+=sum(a[i]-1),add(a[i]);
    printf("%lld",ans);
    return 0;
}
