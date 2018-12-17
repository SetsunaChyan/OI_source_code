#include <cstdio>

typedef long long ll;
ll a[200005];
int n;

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    scanf("%d",&n);
    ll x;
    scanf("%I64d",&x);
    a[0]=0;
    a[n-1]=x;
    for(int i=1;i<n/2;i++)
    {
        scanf("%I64d",&x);
        a[n-i-1]=min(a[n-i],x);
        a[i]=x-a[n-i-1];
        if(a[i]<a[i-1])
        {
            a[i]=a[i-1];
            a[n-i-1]=x-a[i];
        }
    }
    for(int i=0;i<n;i++)
        printf("%I64d ",a[i]);
    return 0;
}