#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int tx[200005],ty[200005],n;
ll bit[200005],vis[200005];
struct node
{
    int x,y;
}p[200005];

void add(int x){for(;x<=n;x+=x&-x) bit[x]+=1;}
ll sum(int x){ll ret=0; for(;x>0;x-=x&-x) ret+=bit[x]; return ret;}
int _find(int a[],int x){return lower_bound(a,a+n,x)-a+1;}
bool cmp(node a,node b){return a.y>b.y||a.y==b.y&&a.x<b.x;}

int main()
{
    ll ans=0;
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        tx[i]=p[i].x;ty[i]=p[i].y;
    }
    sort(tx,tx+n);
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++) p[i].x=_find(tx,p[i].x);
    for(int i=0;i<n;i++)
    {
        ll l=sum(p[i].x-1),r;
        if(i!=n-1&&p[i].y==p[i+1].y) r=sum(p[i+1].x-1)-sum(p[i].x);
        else r=sum(n)-sum(p[i].x);
        ans+=(l+1)*(r+1);
        if(!vis[p[i].x]) add(p[i].x),vis[p[i].x]=1;
    }
    printf("%llu",ans);
    return 0;
}
