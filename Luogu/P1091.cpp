#include <cstdio>
#include <memory.h>

int ans=0,a[105],b[105],h[105],n;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(int i=0;i<n;i++)
        a[i]=b[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(h[j]<h[i]) a[i]=max(a[i],a[j]+1);
    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>i;j--)
            if(h[j]<h[i]) b[i]=max(b[i],b[j]+1);
    for(int i=0;i<n;i++)
        ans=max(ans,a[i]+b[i]-1);
    printf("%d",n-ans);
    return 0;
}