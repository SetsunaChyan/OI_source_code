#include <bits/stdc++.h>
using namespace std;

int a[10000],n,cnt;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        if(a[0]>a[n-1]) cnt++;
        for(int i=1;i<n;i++)
            if(a[i]>a[i-1]) cnt++;
        if(cnt==n-1||cnt==1) printf("YES\n"); else printf("NO\n");
    }

    return 0;
}
