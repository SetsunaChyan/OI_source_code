#include <bits/stdc++.h>
using namespace std;

int n,a[1005];

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int flag=0;
    for(int i=1;i<n;i++)
        if(a[i]==a[i-1]+1) flag=1;
    printf("%d\n",flag+1);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
