#include <bits/stdc++.h>
using namespace std;

int fa[400005],n,m,q,ans;

int _find(int x){return fa[x]==x?x:fa[x]=_find(fa[x]);}
void _merge(int x,int y){x=_find(x),y=_find(y);if(x!=y) fa[x]=y,ans--;}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    ans=n+m-1;
    for(int i=0;i<n+m;i++) fa[i]=i;
    for(int i=0,x,y;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        x--,y--;
        _merge(x,n+y);
    }
    printf("%d",ans);
    return 0;
}
