#include <bits/stdc++.h>
using namespace std;

int n,k,a[200],c[200],s;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),s+=a[i];
    for(int i=0;i<n;i++)
        c[i%k]+=a[i];
    int ans=0;
    for(int i=0;i<k;i++)
        ans=max(ans,abs(s-c[i]));
    printf("%d",ans);
    return 0;
}
