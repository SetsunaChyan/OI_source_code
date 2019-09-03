#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,r,dp[105][60005],ans;
struct orz
{
    int a,b;
}op[105];

bool cmp(orz x,orz y)
{
    if(x.b>0&&y.b>0) return x.a<y.a;
    if(x.b>0&&y.b<0) return 1;
    if(x.b<0&&y.b>0) return 0;
    if(x.a+x.b==y.a+y.b) return x.b>y.b;
    return x.a+x.b>y.a+y.b;
}

int main()
{
    memset(dp,0xc0,sizeof(dp));
    scanf("%d%d",&n,&r);
    for(int i=0;i<=r;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&op[i].a,&op[i].b);
    sort(op+1,op+n+1,cmp);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=60000;j++)
        {
            if(j-op[i-1].b<op[i-1].a) continue;
            if(j-op[i-1].b<0||j-op[i-1].b>60000) continue;
            dp[i][j]=dp[i-1][j-op[i-1].b]+1;
            ans=max(ans,dp[i][j]);
        }
    //if(ans==n) printf("YES");
    //else printf("NO");
    printf("%d",ans);
    return 0;
}
