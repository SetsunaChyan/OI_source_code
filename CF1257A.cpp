#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,x,a,b;
    scanf("%d%d%d%d",&n,&x,&a,&b);
    if(a>b) swap(a,b);
    int k=min(x,a-1);
    a-=k,x-=k;
    k=min(x,n-b);
    b+=k;
    printf("%d\n",b-a);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
