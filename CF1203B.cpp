#include <bits/stdc++.h>
using namespace std;

int n,a[500],qaq;

bool solve()
{
    scanf("%d",&n);
    for(int i=0;i<4*n;i++) scanf("%d",&a[i]);
    sort(a,a+4*n);
    if(a[0]==a[1]&&a[4*n-1]==a[4*n-2])
        qaq=a[0]*a[4*n-1];
    else
        return false;
    for(int i=1;i<n;i++)
        if(!(a[i*2]==a[i*2+1]&&a[4*n-i*2-1]==a[4*n-i*2-2]&&a[i*2]*a[4*n-i*2-2]==qaq)) return false;
    return true;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) if(solve()) printf("YES\n"); else printf("NO\n");
    return 0;
}
