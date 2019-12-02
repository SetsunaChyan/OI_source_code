#include <bits/stdc++.h>
using namespace std;

int n,k;

int check(int x)
{
    int ret=0;
    while(x)
    {
        if(x%10==4||x%10==7) ret++;
        x/=10;
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&k);
    int ans=0;
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        if(check(x)<=k) ans++;
    }
    printf("%d",ans);
    return 0;
}
