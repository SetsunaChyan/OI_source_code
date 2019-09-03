#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=0,a[100005];
int n,qaq=0,t=1;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]<=-1) ans+=-a[i]-1,t*=-1;
        else if(a[i]==0) qaq++,ans+=1;
        else ans+=a[i]-1;
    }
    if(t==-1&&qaq==0) ans+=2;
    printf("%lld",ans);
    return 0;
}

