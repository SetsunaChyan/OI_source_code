#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s,n,k;
vector<ll> ans;
int main()
{
    scanf("%lld%lld%lld",&n,&k,&s);
    n--;
    if(n*k<s||k>s) return printf("NO"),0;
    printf("YES\n");
    ll now=1,stp=s/k;
    for(int i=1;i<=k;i++) ans.push_back(stp);
    for(int i=0;i<k;i++)
    {
        if(i<s%k) ans[i]++;
        if(i&1) now-=ans[i]; else now+=ans[i];
        printf("%lld ",now);
    }
    return 0;
}
