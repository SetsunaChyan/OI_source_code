#include <bits/stdc++.h>
using namespace std;

int n,k,a[100005],mm=0x3f3f3f3f,mx=-0x3f3f3f3f,pre[100005],ans=-0x3f3f3f3f;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i),mm=min(mm,a[i]),mx=max(mx,a[i]);
        if(i==0) pre[i]=a[i];
        else pre[i]=min(pre[i-1],a[i]);
    }
    if(k==1) return printf("%d",mm),0;
    if(k>=3) return printf("%d",mx),0;
    mm=0x3f3f3f3f;
    for(int i=n-1;i;i--)
    {
        mm=min(mm,a[i]);
        ans=max(ans,max(mm,pre[i-1]));
    }
    printf("%d",ans);
    return 0;
}
