#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100005],b[100005],s[100005],ans,qaq[66];
map<ll,int> m;

int f(ll x)
{
    int ret=0;
    while(x) x<<=1,ret++;
    return ret+1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i),m[a[i]]++;
    for(int i=0;i<n;i++)
        scanf("%lld",b+i);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if((a[i]|a[j])==a[j]) s[j]+=b[i];
    for(int i=0;i<n;i++)
        if(m[a[i]]>1) ans=max(ans,s[i]),qaq[__built_ina[i])]+=s[i];
    for(int i=0;i<62;i++)
        ans=max(ans,qaq[i]);
    printf("%lld",ans);
    return 0;
}
