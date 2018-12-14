#include <cstdio>
#include <algorithm>

typedef long long ll;
int n,flag=0;
ll q=1ll<<32,w=1ll<<32,e=1ll<<32,a[2000],sum;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    scanf("%lld",&sum);
    std::sort(a,a+n);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;j<n;k++)
            {
                if(a[i]+a[j]+a[k]==sum)
                {
                    if(a[i]<q||(a[i]==q&&a[j]<w))
                    {
                        flag=1;
                        q=a[i];
                        w=a[j];
                        e=a[k];
                    }
                }
                if(a[i]+a[j]+a[k]>=sum) break;
            }
    if(flag)
        printf("%lld %lld %lld",q,w,e);
    else
        printf("NO");
    return 0;
}