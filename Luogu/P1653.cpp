#include <bits/stdc++.h>
using namespace std;

int n,m,l[200005],r[200005],fa1[200005],fa2[200005],rl[200005],ll[200005],ans[200005];
struct op
{
    int num,hand;
}e[400005];

int _find(int fa[],int x)
{
    if(fa[x]==x) return x;
    return fa[x]=_find(fa,fa[x]);
}

void _un(int fa[],int x,int y)
{
    fa[_find(x)]=_find(y);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa1[i]=fa2[i]=0,rl[i]=ll[i]=0;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&e[i].num,&e[i].hand);
        if(e[i].hand==1) ll[e[i].num]=1;
        else rl[e[i].num]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!ll[i]&&~l[i])
        {
            _un(fa1,i,l[i]);
            _un(fa2,i,l[i]);
        }
        if(!rl[i]&&~r[i])
        {
            _un(fa1,i,r[i]);
            _un(fa2,i,r[i]);
        }
    }
    ans[1]=-1;
    for(int i=m-1;i>=0;i--)
    {
        if()


    }
    return 0;
}
