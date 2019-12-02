#include <bits/stdc++.h>
using namespace std;
int n,to[200005],in[200005],d[200005];
bool p[200005];
void down(int x);
void up(int x)
{
    //printf("up %d\n",x);
    p[x]=0;
    d[to[x]]++;
    if(p[to[x]]==0)down(to[x]);
}
void down(int x)
{
    //printf("down %d\n",x);
    p[x]=1;
    --d[to[x]];
    if(!d[to[x]]&&p[to[x]]==1)up(to[x]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n+n;++i)scanf("%d",&to[i]),in[to[i]]++;
    for(int i=1;i<=n+n;i++)p[i]=i>n;
    for(int i=1;i<=n;i++)++d[to[i]];
    for(int i=n+1;i<=n+n;i++)
        if(!in[i]&&p[i]==1)
            up(i);
    for(int i=1;i<=n+n;i++)if(!p[i])printf("%d ",i);
    return 0;
}
