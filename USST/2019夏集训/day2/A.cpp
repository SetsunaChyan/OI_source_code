#include <bits/stdc++.h>
using namespace std;

int n,a[1005],ans,t;

int main()
{
    ans=0;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(abs(a[i]-a[j])<=t) ans++;
    printf("%d",ans<<1);

    return 0;
}
