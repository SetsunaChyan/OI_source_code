#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[2005],n,m;
double dp[2005];
char s[10];

void solve()
{
    int cur=m,last=m;
    memset(p,-1,sizeof(p));
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        if(strlen(s)==2) p[cur]=10;
        if(s[0]>='2'&&s[0]<='9') p[cur]=s[0]-'0';
        else if(s[0]=='A') p[cur]=11;
        else p[cur]=10;
        last=cur;
        cur+=p[cur];
    }
    for(int i=11;i<=cur;i++) dp[i]=0;
    for(int i=1;i<=10;i++) dp[i]=0.1;
    for(int i=1;i<=last;i++)
        if(p[i]!=-1) dp[i+p[i]]+=dp[i];
        else
            for(int j=1;j<=13;j++)
            {
                int t;
                if(j==1) t=11;
                else if(j>=10) t=10;
                else t=j;
                dp[i+t]+=dp[i]/13.0;
            }
    printf("%.12f\n",dp[last]);
}

int main()
{
    while(~scanf("%d%d",&n,&m)) solve();
    return 0;
}
