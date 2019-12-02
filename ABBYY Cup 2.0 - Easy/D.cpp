#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,c;
ll a[100005],b[100005],dif[100005];

int main()
{
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=m;i++)
        dif[i]+=b[i],dif[n-m+i+1]=(dif[n-m+i+1]-b[i]+c)%c;
    for(int i=1;i<=n;i++) dif[i]+=dif[i-1],dif[i]%=c;
    for(int i=1;i<=n;i++) a[i]+=dif[i],a[i]%=c,printf("%lld ",a[i]);
    return 0;
}
