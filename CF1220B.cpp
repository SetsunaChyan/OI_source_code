#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[1005][1005];
ll ans[1005];

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    ans[0]=sqrt((long long)a[0][1]*a[0][2]/a[1][2]);
    for(int i=1;i<n;i++)
        ans[i]=a[i][i-1]/ans[i-1];
    for(int i=0;i<n;i++)
        printf("%lld ",ans[i]);
}

int main()
{
    solve();
    return 0;
}

