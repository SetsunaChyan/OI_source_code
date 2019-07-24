#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans,qaq[11];
char s[20];

void solve()
{
    ans=0;
    for(int i=2;i<=10;i++) qaq[i]=1;
    scanf("%s",s);
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]-'0')
            for(int j=2;j<=10;j++) ans+=qaq[j];
        for(int j=2;j<=10;j++) qaq[j]*=j;
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
