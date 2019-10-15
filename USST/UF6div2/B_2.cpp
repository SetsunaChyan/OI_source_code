#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
char s[1000];
int l;
ll qaq[3][3];

void solve(int l,int r,ll dp[3][3])
{
    if(l==r-1)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                dp[i][j]=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j) dp[i][j]=1;
        dp[1][2]=dp[2][1]=0;
        return;
    }
    int now=l,stk=0,flag=0;
    ll ndp[3][3],tdp[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ndp[i][j]=tdp[i][j]=0;
    while(now<=r)
    {
        for(int ii=now;ii<=r;ii++)
        {
            if(s[ii]=='(') stk++;
            else stk--;
            if(stk==0&&ii==r&&now==l)
            {
                solve(l+1,r-1,ndp);
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                    {
                        if(i==j) continue;
                        if(i==1&&j==2||i==2&&j==1) continue;
                        for(int I=0;I<3;I++)
                            for(int J=0;J<3;J++)
                                if(i!=I&&j!=J||i+I==0&&j!=J||j+J==0&&i!=I) dp[i][j]=(dp[i][j]+ndp[I][J])%mod;
                    }
                return;
            }
            if(stk==0)
            {
                if(flag==0)
                {
                    solve(now,ii,ndp);
                    for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                            dp[i][j]=ndp[i][j];
                    now=ii+1;
                    flag++;
                    break;
                }
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        ndp[i][j]=0;
                solve(now,ii,ndp);
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        tdp[i][j]=0;
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        for(int I=0;I<3;I++)
                            for(int J=0;J<3;J++)
                                if(j!=I||j+I==0) tdp[i][J]+=dp[i][j]*ndp[I][J]%mod,tdp[i][J]%=mod;
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        dp[i][j]=tdp[i][j];
                now=ii+1;
                break;
            }
        }
    }
}

int main()
{
    scanf("%s",s);
    l=strlen(s);
    solve(0,l-1,qaq);
    ll ans=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ans+=qaq[i][j],ans%=mod;
    printf("%lld",ans);
    return 0;
}
