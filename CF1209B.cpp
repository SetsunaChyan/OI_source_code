#include <bits/stdc++.h>
using namespace std;

int ans,n,a[1005],b[1005],s[1005];

int f()
{
    int ret=0;
    for(int i=0;i<n;i++)
        if(s[i]) ret++;
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%1d",&s[i]);
    for(int i=0;i<n;i++)
        scanf("%d%d",a+i,b+i);
    for(int i=0;i<10000;i++)
    {
        for(int j=0;j<n;j++)
            if(b[j]<=i&&(i-b[j])%a[j]==0) s[j]^=1;
        ans=max(ans,f());
    }
    printf("%d",ans);
    return 0;
}
