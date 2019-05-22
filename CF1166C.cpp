#include <bits/stdc++.h>
using namespace std;

long long ans=0;
int n,a[200005],k;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=abs(a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        int k=lower_bound(a,a+n,(a[i]+1)/2)-a;
        //if(!a[i]) ans+=n-1;
        if(k<n) ans+=i-k;
        //printf("%d %d \n",i,ans);
    }
    printf("%lld",ans);
    return 0;
}