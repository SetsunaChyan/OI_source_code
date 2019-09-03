#include <bits/stdc++.h>
using namespace std;

int n,m,k,now,a[1000];

void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    now=m;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]>=a[i]+k)
        {
            now-=a[i+1]-k-a[i];
            if(now<0)
            {
                printf("NO\n");
                return;
            }
        }
        else
        {
            int qaq=a[i]+k-a[i+1];
            if(qaq>a[i]) qaq=a[i];
            now+=qaq;
        }
    }
    printf("YES\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();

    return 0;
}
