#include <cstdio>
#include <memory.h>

int a[100005],n,m,t[100005];

int main()
{
    memset(t,0,sizeof(t));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(m--)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        t[l-1]^=x;
        t[r]^=x;
    }
    for(int i=1;i<n;i++)
        t[i]^=t[i-1];
    for(int i=0;i<n;i++)
        printf("%d ",a[i]^t[i]);
    return 0;
}