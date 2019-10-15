#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,h,a[200005];

void solve()
{
    int ans=0;
    scanf("%d%d",&h,&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    a[n]=0;
    for(int i=1;i<n;i++)
        if(a[i]-a[i+1]>=2) ans++; else i++;
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
