#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[600005];

int main()
{
    ll ans=0;
    int n;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
    {
        int k=s[i]-'0';
        if(k&1) ans+=i+1;
    }
    printf("%lld",ans);
    return 0;
}
