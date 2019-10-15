#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double dp[205][205][205];
int n,l,k;
struct node
{
    int p,bag;
}a[205];

bool cmp(node a,node b)
{
    return a.bag>b.bag;
}

int main()
{
    scanf("%d%d%d",&n,&l,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i].p);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i].bag);
    sort(a,a+n,cmp);
    dp[0][0][k]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=200;k++)
            {
                double p=a[i].p/100.0;
                if(k+a[i].bag>=0) dp[i+1][min(j+1,n)][min(k+a[i].bag,200)]+=p*dp[i][j][k];
                dp[i+1][j][k]+=(1-p)*dp[i][j][k];
            }
    double ans=0;
    for(int i=l;i<=n;i++)
        for(int j=0;j<=200;j++)
            ans+=dp[n][i][j];
    printf("%.10f",ans);
    return 0;
}
