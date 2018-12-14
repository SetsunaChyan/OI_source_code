#include <cstdio>

int fa[10002];

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void union1(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
        fa[a]=b;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) fa[i]=i;
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        union1(x,y);
    }
    int ans=-1;
    for(int i=1;i<=n;i++) if(find(i)==i) ans++;
    if(ans==-1)
        printf("0");
    else
        printf("%d",ans);
    return 0;
}