#include <bits/stdc++.h>
using namespace std;

int fa[2000005],op,q,z[2000005],x[2000005],n,vis[2000005],org[2000005],tmp[2000005],tot;

int _find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=_find(fa[x]);
}

void _merge(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x!=y) fa[x]=y;
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&z[i],&x[i]);
        tmp[tot++]=x[i];
        x[i+q]=x[i]+1;
        tmp[tot++]=x[i]+1;
    }
    sort(tmp,tmp+tot);
    int len=unique(tmp,tmp+tot)-tmp;
    for(int i=1;i<=len;i++) fa[i]=i;
    for(int i=0;i<tot;i++)
    {
        int k=lower_bound(tmp,tmp+len,x[i])-tmp+1;
        org[k]=x[i];
        x[i]=k;
    }
    for(int i=0;i<q;i++)
    {
        if(z[i]==1)
        {
            if(vis[x[i]]) continue;
            vis[x[i]]=1;
            _merge(x[i],x[i]+1);
            continue;
        }
        int k=_find(x[i]);
        if(org[k]==n+1) printf("-1\n");
        else printf("%d\n",org[k]);
    }
    return 0;
}
