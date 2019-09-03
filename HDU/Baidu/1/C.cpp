#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<ld,int> pli;

const int mv[4][2]={0,1,1,0,-1,0,0,-1};
vector<int> e[200005];
vector<ld> val[200005];
int n,x1[255],y1[255],x2[255],y2[255],tmpx[455],tmpy[455],totx,toty;
int vis[455][455],xa,xb,ya,yb;
ld dis[200005];
int viss[200005];

ld dij()
{
    priority_queue<pli> q;
    for(int i=1;i<=totx;i++)
        for(int j=1;j<=toty;j++)
            viss[i*toty+j]=0,dis[i*toty+j]=1e30;
    dis[xa*toty+ya]=0;
    q.emplace(0,xa*toty+ya);
    while(!q.empty())
    {
        pli p=q.top();
        q.pop();
        int now=p.second;
        if(viss[now]) continue;
        viss[now]=1;
        for(int i=0;i<e[now].size();i++)
        {
            int to=e[now][i];ld v=val[now][i];
            if(v+p.first<dis[to])
            {
                dis[to]=v+p.first;
                q.emplace(dis[to],to);
            }
        }
    }
    return dis[xb*toty+yb];
}

void solve()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        tmpx[i*2]=x1[i];
        tmpx[i*2+1]=x2[i];
        tmpy[i*2]=y1[i];
        tmpy[i*2+1]=y2[i];
    }
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    tmpx[n*2]=xa,tmpx[n*2+1]=xb,tmpy[n*2]=ya,tmpy[n*2+1]=yb;
    for(int i=0;i<=4*n*n+4;i++)
        e[i].clear(),val[i].clear();
    sort(tmpx,tmpx+2*n+2);
    sort(tmpy,tmpy+2*n+2);
    totx=unique(tmpx,tmpx+2*n+2)-tmpx;
    toty=unique(tmpy,tmpy+2*n+2)-tmpy;
    printf("qaq\n");
    for(int i=0;i<n;i++)
    {
        x1[i]=lower_bound(tmpx,tmpx+totx,x1[i])-tmpx;
        x2[i]=lower_bound(tmpx,tmpx+totx,x2[i])-tmpx;
        y1[i]=lower_bound(tmpy,tmpy+toty,y1[i])-tmpy;
        y2[i]=lower_bound(tmpy,tmpy+toty,y2[i])-tmpy;
        for(int x=x1[i];x<=x2[i];x++)
            for(int y=y1[i];y>=y2[i];y++)
                vis[x][y]++;
    }
    printf("qaq\n");
    xa=lower_bound(tmpx,tmpx+totx,xb)-tmpx;
    xb=lower_bound(tmpx,tmpx+totx,xa)-tmpx;
    ya=lower_bound(tmpy,tmpy+toty,ya)-tmpy;
    yb=lower_bound(tmpy,tmpy+toty,yb)-tmpy;
    printf("qaq\n");
    for(int i=0;i<totx;i++)
        for(int j=0;j<toty;j++)
            for(int k=0;k<4;k++)
            {
                int dx=i+mv[k][0],dy=j+mv[k][1];
                if(dx>=0&&dx<totx&&dy>=0&&dy<toty)
                {
                    printf("%d %d -> %d %d : %d\n",tmpx[i],tmpy[i],tmpx[dx],tmpy[dy],abs(tmpx[dx]-tmpx[i])+abs(tmpy[dy]-tmpy[j]));
                    e[i*toty+j].push_back(dx*toty+dy);
                    val[i*toty+j].push_back((ld)1/(ld)(1+abs(tmpx[dx]-tmpx[i])+abs(tmpy[dy]-tmpy[j])));
                }
            }
    printf("qaq %d %d\n",totx,toty);
    printf("%.5Lf\n",dij());
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
