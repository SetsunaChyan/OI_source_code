#include <bits/stdc++.h>
using namespace std;

int n,r,x;

void solve()
{
    scanf("%d%d",&n,&r);
    int cur=1500;
    while(n--)
    {
        scanf("%d",&x);
        cur+=x;
    }
    if(cur==r) printf("Correct\n");
    else printf("Bug\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
