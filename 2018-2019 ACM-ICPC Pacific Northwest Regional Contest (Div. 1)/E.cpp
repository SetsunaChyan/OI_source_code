#include <bits/stdc++.h>
using namespace std;
int n,m,cc,c[33],ans=2e9,dp[33][33];
char s[33][33];
int main()
{
    scanf("%d%d%d",&n,&m,&cc);
    int bx,by;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++)
            if(s[i][j]=='B')
                bx=i,by=j;
    }
    for(int i=0;i<cc;i++)
        scanf("%d",c+i);
    for(int u=1;u<bx;u++)
        for(int d=bx+1;d<=n;d++,d=n+1)
            for(int l=1;l<by;l++)
                for(int r=by+1;r<=m;r++,r=m+1)
                {
                    int t=0;
                    //ul
                    printf("%d %d\n",u,l);
                    memset(dp,0x3f,sizeof(dp));
                    dp[u][by-1]=c[s[u][by]-'a']+c[s[bx][l]-'a'];
                    dp[u][by-1]+=(2-(u==bx-1&&by-1==l))*c[s[u][by-1]-'a']+c[s[bx-1][l]-'a'];
                    for(int i=u;i<bx-1;i++)
                        for(int j=by-1;j>=l;j--)
                        {
                            if(s[i+1][j]!='.')dp[i+1][j]=min(dp[i+1][j],dp[i][j]+c[s[i+1][j]-'a']);
                            dp[i][j-1]=min(dp[i][j-1],dp[i][j]+c[s[i][j-1]-'a']),
                            dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+c[s[i+1][j-1]-'a']);
                        }
                    for(int i=1;i<=bx;i++)
                        for(int j=1;j<=by;j++)
                            printf("%d%c",dp[i][j]," \n"[j==by]);
                    puts("");
                    t+=dp[bx-1][l];



                    ans=min(ans,t);
                }
    printf("%d\n",ans==2e9?-1:ans);
    return 0;
}
