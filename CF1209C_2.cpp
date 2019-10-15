#include <bits/stdc++.h>
using namespace std;

int n,a[200005],dp[200005],ans[200005];
char ss[200005];

bool chk(int x)
{
    int i,lst=x,cnt=0;
    for(int i=1;i<=n;i++) ans[i]=0;
    for(int i=n;i>=1;i--) if(a[i]<=lst) ans[i]=1,lst=a[i];
    for(int i=1;i<=n;i++) if(!ans[i]) ans[i]=2;
    for(int i=1;i<=n;i++) if(ans[i]==1) ss[cnt++]='0'+a[i];
    for(int i=1;i<=n;i++) if(ans[i]==2) ss[cnt++]='0'+a[i];
    for(int i=1;i<n;i++) if(ss[i]<ss[i-1]) return false;
    return true;
}

void solve()
{
    scanf("%d",&n);
    scanf("%s",ss+1);
    for(int i=1;i<=n;i++)
        a[i]=ss[i]-'0';
    for(int i=0;i<10;i++)
        if(chk(i))
        {
            for(int j=1;j<=n;j++) printf("%d",ans[j]);
            printf("\n");
            return;
        }
    printf("-\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

