#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ans,pre[300005];
char s[300005];

int main()
{
    scanf("%d%s",&n,s);
    ans=(long long)n*(n+1ll)/2-n;
    ll cnt=0;
    for(int i=0;i<n;i++)
        if(s[i]=='A') cnt++; else ans-=cnt,cnt=0;
    cnt=0;
    for(int i=n-1;i>=0;i--)
        if(s[i]=='A') cnt++; else ans-=cnt,cnt=0;
    cnt=0;
    for(int i=0;i<n;i++)
        if(s[i]=='B') cnt++; else ans-=cnt,cnt=0;
    cnt=0;
    for(int i=n-1;i>=0;i--)
        if(s[i]=='B') cnt++; else ans-=cnt,cnt=0;
    for(int i=0;i<n-1;i++)
        if(s[i]!=s[i+1]) ans++;
    printf("%lld",ans);
    return 0;
}
