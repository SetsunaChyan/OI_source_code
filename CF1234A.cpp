#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,x,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&x),s+=x;
    if(s%n) s=s/n+1; else s=s/n;
    printf("%d\n",s);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
