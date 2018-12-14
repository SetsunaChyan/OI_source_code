#include <cstdio>

int n;
long long l,r,sum=0,sa=0,sb=0,a[100005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    scanf("%lld%lld",&l,&r);
    for(int i=0;i<n;i++)
    {
        if(a[i]>r) sa+=a[i]-r;
        if(a[i]<l) sb+=l-a[i];
    }
    if(sum<l*n||sum>r*n)
        printf("-1");
    else
        printf("%lld",sa>sb?sa:sb);
    return 0;
}
