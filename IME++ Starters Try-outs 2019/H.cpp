#include <bits/stdc++.h>
using namespace std;

int n,p,q,a,b,pr[1000005],phi[1000005];
bool f[1000005];

int main()
{
    phi[1]=1;
    for(int i=2;i<1000005;i++)
    {
        if(!f[i]) phi[pr[++p]=i]=i-1;
        for(int j=1,k;j<=p&&(k=i*pr[j])<1000005;j++)
        {
            f[k]=1;
            if(i%pr[j]) phi[k]=phi[i]*(pr[j]-1);
            else {phi[k]=phi[i]*pr[j];break;}
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)==1) printf("%d\n",phi[b]);
        else printf("-1\n");
    }
    return 0;
}
