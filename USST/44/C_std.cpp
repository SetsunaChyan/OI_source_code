#include <bits/stdc++.h>
using namespace std;

int fa[500005],cnt[500005],vis[500005],n,m,op,x,y;

int fd(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=fd(fa[x]);
}

void con(int x,int y)
{
    x=fd(x),y=fd(y);
    if(x==y) return;
    fa[x]=y;
    cnt[y]+=cnt[x];
}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m); 
    for(int i=1;i<=n;i++) fa[i]=i,cnt[i]=1;
    while(m--)
    {
        scanf("%d%d",&op,&x);
        if(op==1)
        {
            scanf("%d",&y);
            con(x,y);
        }
        else if(op==2)
        {
            if(!vis[x]) cnt[fd(x)]--,vis[x]=1;
        }
        else
            printf("%d\n",cnt[fd(x)]);
    }
    return 0;
}