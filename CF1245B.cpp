#include <bits/stdc++.h>
using namespace std;

int n,r,p,S,cnt;
char s[105],ans[105];

void solve()
{
    cnt=0;
    scanf("%d%d%d%d",&n,&r,&p,&S);
    scanf("%s",s);
    for(int i=0;i<=n;i++) ans[i]=0;
    for(int i=0;i<n;i++)
        if(s[i]=='P'&&S) ans[i]='S',S--,cnt++;
        else if(s[i]=='R'&&p) ans[i]='P',p--,cnt++;
        else if(s[i]=='S'&&r) ans[i]='R',r--,cnt++;
    if(cnt>=(n+1)/2) printf("YES\n");
    else
    {
        printf("NO\n");
        return;
    }
    for(int i=0;i<n;i++)
        if(ans[i]==0)
        {
            if(S) ans[i]='S',S--;
            else if(p) ans[i]='P',p--;
            else if(r) ans[i]='R',r--;
        }
    printf("%s\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
