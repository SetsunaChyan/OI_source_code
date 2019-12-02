#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int n,c,dp[10005],from[505][10005];
struct node
{
    int d,s,num;
}a[505];

inline bool cmp(node a,node b){return a.s-a.d<b.s-b.d;}

int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].d,&a[i].s),a[i].num=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        for(int j=c;j>=a[i].s;j--)
            if(c-j+a[i].s>=a[i].d&&dp[j]<dp[j-a[i].s]+1) dp[j]=dp[j-a[i].s]+1,from[i][j]=1;
    int i=n,j=c,mx=-1;
    for(int i=0;i<=c;i++) if(dp[i]>mx) j=i,mx=dp[i];
    while(i)
    {
        if(from[i][j]) ans.push_back(a[i].num),j-=a[i].s;
        i--;
    }
    printf("%d\n",(int)ans.size());
    for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
    return 0;
}

/*
2 100
500 1
1 500
*/
