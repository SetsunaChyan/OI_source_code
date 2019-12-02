#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,sa[100005],safe[100005];
ll mo[100005],pre[100005];
double dp[100005][3],w,p[100005],pp[100005],ans,p_pre[100005];
char s[100];

int main()
{
    scanf("%d%d",&n,&w);
    p_pre[0]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%s%lf%lld",s,&p[i],&mo[i]);
        pre[i]=pre[i-1]+mo[i];
        p_pre[i]=p_pre[i-1]*p[i];

        printf("! %.10f %.10f\n",p_pre[i],p[i]);
        if(s[0]=='s') sa[i]=1;
    }
    p[n+1]=1,mo[n+1]=0,pp[0]=1;
    n++;
    int now=0;
    for(int i=1;i<=n;i++)
    {
        safe[i]=now;
        if(sa[i]) now=i;
        if(sa[i-1]) pp[i]=1; else pp[i]=pp[i-1]*p[i];
    }
    //dp[0][1]=1;
    for(int i=1;i<=n;i++)
    {
        //dp[i][0]=dp[i-1][1];
        dp[i][1]=p_pre[i]*pre[i];
        printf("! %.10f\n",dp[i][1]);
        dp[i][2]=(1-p[i])*dp[s[i]][1]*pp[i];
    }
    for(int i=1;i<=n;i++) ans=max(ans,dp[i][1]+dp[i][2]);
    printf("%.10f",ans);
    return 0;
}

/*
1 4000
unsafe 0.5 500
*/
