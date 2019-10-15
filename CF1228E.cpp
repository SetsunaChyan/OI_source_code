#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
int n,k,m[255][255],ans;
// Sum_{s=0..n} binomial(n, s)*(-1)^s*2^((n-s)*n)*(1-2^(-n+s))^n

int c(int n,int k)
{
    int ret=1;
    for(int i=n;i>n-k;i--)
        ret*=i;
    for(int i=1;i<=k;i++)
        ret/=i;
    return ret;
}

int p(int x,int y)
{
    int ret=1;
    for(int i=0;i<y;i++) ret*=x;
    return ret;
}

bool check()
{
    for(int i=0;i<n;i++)
    {
        int mm=inf;
        for(int j=0;j<n;j++)
            mm=min(mm,m[i][j]);
        if(mm!=1) return false;
    }
    for(int i=0;i<n;i++)
    {
        int mm=inf;
        for(int j=0;j<n;j++)
            mm=min(mm,m[j][i]);
        if(mm!=1) return false;
    }
    return true;
}

void dfs(int x)
{
    if(x==n*n)
    {
        if(check()) ans++;
        return;
    }
    for(int i=1;i<=k;i++)
    {
        m[x/n][x%n]=i;
        dfs(x+1);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(0);
    printf("%d\n",ans);
    int ans2=0;
    for(int s=0;s<=n;s++)
        //Sum_{s=0..n} binomial(n, s)*(-1)^s*2^((n-s)*n)*(1-2^(-n+s))^n
        ans2+=c(n,s)*p(-1,s)*(p(2,n-s)-1);
    printf("%d",ans2);
    return 0;
}
