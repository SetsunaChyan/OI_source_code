#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,r,a[200005],k,cnt;
int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]),l=max(a[i],l);
    sort(a,a+n);
    int i;
    for(i=1;i<n;i++)
        if(a[i]!=a[i-1])
        {
            k=a[i]-a[i-1];
            break;
        }
    for(i++;i<n;i++)
        if(a[i]!=a[i-1]) k=__gcd(k,a[i]-a[i-1]);
    //printf("QAQ");
    for(int i=0;i<n;i++)
        cnt+=(l-a[i])/k;
    printf("%lld %lld",cnt,k);
    return 0;
}
