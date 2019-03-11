#include <cstdio>
#include <algorithm>

int ans=1,a[200005],q[200005],n,head=0,end=0;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::sort(a,a+n);
    q[end++]=0;
    for(int i=1;i<n;i++)
    {
        while(head<end&&a[q[head]]<a[i]-5) head++;
        q[end++]=i;
        ans=max(ans,end-head);
    }
    printf("%d",ans);
    return 0;
}