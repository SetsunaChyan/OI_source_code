#include <cstdio>
#include <memory.h>

int flag=0,vis[6000],v[6000],b[6000],cnt[6000],k,n,tot=0;

int main()
{
    memset(vis,0,sizeof(vis));
    memset(v,0,sizeof(v));
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        vis[b[i]]++;
        cnt[b[i]]++;
        if(vis[b[i]]>k) {flag=1;break;}
    }
    if(flag)
    {
        printf("NO");
        return 0;
    }
    for(int i=1;i<=5000;i++)
        vis[i]+=vis[i-1];
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",(v[b[i]]-cnt[b[i]]+vis[b[i]])%k+1);
        v[b[i]]++;
    }
    return 0;
}