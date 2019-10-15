#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q;
ll b[105][105][11],c;

int main()
{
    scanf("%d%d%lld",&n,&q,&c);
    for(int i=0;i<n;i++)
    {
        int x,y,qaq;
        scanf("%d%d%d",&x,&y,&qaq);
        b[x][y][qaq]++;
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            for(int k=0;k<=c;k++)
                b[i][j][k]+=b[i-1][j][k]+b[i][j-1][k]-b[i-1][j-1][k];
    while(q--)
    {
        int x1,y1,x2,y2;
        ll t;
        scanf("%lld%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        x1--,y1--;
        ll ans=0;
        for(int i=0;i<=c;i++)
            ans+=(b[x1][y1][i]+b[x2][y2][i]-b[x1][y2][i]-b[x2][y1][i])*((t+i)%(c+1));
        printf("%lld\n",ans);
    }
    return 0;
}
