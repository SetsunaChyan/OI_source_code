#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[400005],sum=0,pre[400005];
ll mx,mi;
int n,tot;

int main()
{
    int cur=0;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        a[cur]=i;
        if(i&1) cur=(cur+n)%(2*n);
        else cur=(cur+2*n-1)%(2*n);
    }
    for(int i=2*n;i<4*n;i++)
        a[i]=a[i-2*n];
    pre[0]=a[0];
    for(int i=1;i<4*n;i++)
        pre[i]=pre[i-1]+a[i];
    mx=mi=pre[n]-pre[0];
    for(int i=n+1;i<4*n;i++)
    {
        mx=max(mx,pre[i]-pre[i-n]);
        mi=min(mi,pre[i]-pre[i-n]);
    }
    if(mx-mi>1)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i=0;i<2*n;i++) printf("%d ",a[i]);
    return 0;
}

