#include <bits/stdc++.h>
using namespace std;

int flag,n,m,fa[5000];

int f(int x){return fa[x]==x?x:fa[x]=f(fa[x]);}

void con(int x,int y)
{
    x=f(x),y=f(y);
    fa[x]=y;
}

void solve()
{
    flag=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<(n<<1);i++) fa[i]=i;
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(flag) continue;
        if(f(x)==f(y))
        {
            flag=1;
            continue;
        }
        con(x,y+n);
        con(x+n,y);
    }
    if(flag) printf("Warning\n"); else printf("Ok\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}