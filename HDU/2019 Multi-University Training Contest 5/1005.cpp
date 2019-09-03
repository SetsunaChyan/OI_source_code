#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[25],k;
ll p,t;

void solve()
{
    scanf("%d%d",&n,&k);
    p=1;
    for(int i=1;i<n;i++) p*=i;
    for(int i=1;i<n;i++) a[i]=i;
    t=n-(k-1)/p;
    k=(k-1)%p;
    for(int i=0;i<k;i++)
        next_permutation(a+1,a+n);
    printf("%lld ",t);
    for(int i=1;i<n;i++)
        printf("%d%c",a[i]>=t?a[i]+1:a[i]," \n"[i==n-1]);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
