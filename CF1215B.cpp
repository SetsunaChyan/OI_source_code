#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[200005],d[200005][2],pos,neg;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        if(a[i]<0) a[i]=-1;
        else a[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            d[i][0]=d[i-1][0]+1;
            d[i][1]=d[i-1][1];
        }
        else
        {
            d[i][0]=d[i-1][1];
            d[i][1]=d[i-1][0]+1;
        }
    }
    for(int i=1;i<=n;i++)
         pos+=d[i][0],neg+=d[i][1];
        //if(a[i]>0) pos+=d[i][0],neg+=d[i][1];
        //else pos+=d[i][1],neg+=d[i][0];
    printf("%lld %lld\n",neg,pos);
    return 0;
}
