#include <bits/stdc++.h>
using namespace std;

const int MAXN=150000;
const int inf=0x7fffffff;
int n,ansx,ansy;
int x1[MAXN],y1[MAXN],x2[MAXN],y2[MAXN],prex1[MAXN],prex2[MAXN],prey1[MAXN],prey2[MAXN],sufx1[MAXN],sufx2[MAXN],sufy1[MAXN],sufy2[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    prex1[0]=prey1[0]=sufx1[n+1]=sufy1[n+1]=-inf;
    prex2[0]=prey2[0]=sufx2[n+1]=sufy2[n+1]=inf;
    for(int i=1;i<=n;i++)
    {
        prex1[i]=max(prex1[i-1],x1[i]);
        prey1[i]=max(prey1[i-1],y1[i]);
        prex2[i]=min(prex2[i-1],x2[i]);
        prey2[i]=min(prey2[i-1],y2[i]);
    }
    for(int i=n;i;i--)
    {
        sufx1[i]=max(sufx1[i+1],x1[i]);
        sufy1[i]=max(sufy1[i+1],y1[i]);
        sufx2[i]=min(sufx2[i+1],x2[i]);
        sufy2[i]=min(sufy2[i+1],y2[i]);
    }
    for(int i=1;i<=n;i++)
        if(max(prex1[i-1],sufx1[i+1])<=min(prex2[i-1],sufx2[i+1])&&max(prey1[i-1],sufy1[i+1])<=min(prey2[i-1],sufy2[i+1]))
        {
            ansx=max(prex1[i-1],sufx1[i+1]);
            ansy=max(prey1[i-1],sufy1[i+1]);
        }
    printf("%d %d",ansx,ansy);
    return 0;
}
