#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[2],a[100005];

int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        s[1]=s[0]=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld",a+i);
        sort(a,a+n);
        for(int i=n-1,j=0;i>=0;i--,j^=1)
            s[j]+=a[i];
        printf("%lld %lld\n",s[0],s[1]);
    }
    return 0;
}
