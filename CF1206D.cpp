#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=0x3f3f3f3f;
vector<ll> a;
ll b[100005],mp[305][305],dis[305][305];
int n;

ll floyd()
{
    int i,j,k;
    ll mina=inf;
    for(k=0;k<n;k++)
    {
        for(i=0;i<k;i++)
            for(j=0;j<i;j++)
                mina=min(dis[i][j]+mp[j][k]+mp[k][i],mina);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
               if(dis[i][j]>(dis[i][k]+dis[k][j]))
                    dis[i][j]=dis[i][k]+dis[k][j];
    }
    return mina;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",b+i);
    for(int i=0;i<n;i++)
        if(b[i]) a.push_back(b[i]);
    n=a.size();
    if(n>=300)
    {
        printf("3\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dis[i][j]=mp[i][j]=inf;
        dis[i][i]=mp[i][i]=0;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i]&a[j]) dis[i][j]=mp[i][j]=1;
    ll k=floyd();
    if(k==inf) printf("-1"); else printf("%lld",k);
    return 0;
}

