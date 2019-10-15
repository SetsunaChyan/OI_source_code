#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll a[]={0,1,2,5,10,20,50,100};
const ll b[]={0,5,10,20,50,100,200};

ll n,d,e,ans;

int main()
{
    scanf("%lld%lld%lld",&n,&d,&e);
    ans=n;e*=5;
    for(int i=0;i<=n/d;i++)
        ans=min(ans,(n-i*d)%e);
    printf("%lld",ans);
    return 0;
}
