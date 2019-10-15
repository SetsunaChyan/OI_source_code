#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,a[200005],l,r;
ll sum;

bool check(int x)
{
    ll ret=0;
    for(int i=0;i<n;i++)
        ret+=max(a[i]-i/x,0);
    return ret>=k;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),sum+=a[i];
    if(sum<k) return printf("-1"),0;
    sort(a,a+n,greater<int>());
    l=1,r=n;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    printf("%d",l);
    return 0;
}
