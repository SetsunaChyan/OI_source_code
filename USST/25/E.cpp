#include <cstdio>
#include <memory.h>

int n,son[1005][2],x[1005],z[1005],root,vis[1005];

int build(int l1,int r1,int l,int r)
{
    int t;
    for(int i=l;i<=r;i++)
        if(z[i]==x[l1])
        {
            t=i;
            break;
        }
    if(t!=l) son[x[l1]][0]=build(l1+1,l1+t-l,l,t-1);
    if(t!=r) son[x[l1]][1]=build(l1+t-l+1,r1,t+1,r);
    return x[l1];
}

void dfs(int x)
{
    if(son[x][0]) dfs(son[x][0]);
    if(son[x][1]) dfs(son[x][1]);
    printf("%d ",x);
}

int main()
{
    memset(son,0,sizeof(son));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&z[i]);
    root=build(0,n-1,0,n-1);
    dfs(root);
    return 0;
}