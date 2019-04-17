#include <cstdio>
#include <algorithm>

typedef long long ll;
int n;
ll a[100005],sum=0,m,cnt=0;

int main()
{
    scanf("%lld%d",&m,&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    std::sort(a,a+n);
    //printf("%lld\n",a[0]);
    a[n]=m;
    if(a[0]!=1)
    {
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        ll k;
        if(a[i+1]>=m)
        {
            k=(m-sum)/a[i];
            if(k*a[i]+sum<m) k++;
            cnt+=k;
            break;
        }
        k=(a[i+1]-sum-1)/a[i];
        if(sum+k*a[i]<a[i+1]-1) k++;
        cnt+=k;
        sum+=k*a[i];
    }
    printf("%lld",cnt);
    return 0;
}