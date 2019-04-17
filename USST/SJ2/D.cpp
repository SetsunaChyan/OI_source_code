#include <cstdio>
#include <algorithm>

typedef long long ll;
ll n,a[100005],m;

inline bool find(ll x) {return *std::lower_bound(a,a+n,x)==x;}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    scanf("%lld",&m);
    std::sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]>m) break;
        if(find(m-a[i]))
        {
            printf("%lld %lld",a[i],m-a[i]);
            return 0;
        }
    }
    printf("No");
    return 0;
}