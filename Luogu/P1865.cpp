#include <cstdio>
#include <memory.h>

int l,r,m,pre[1000005],n;

void sel()
{
    memset(pre,0,sizeof(pre));
    for(int i=2;i<=m;i++)
        if(!pre[i])
            for(int j=i<<1;j<=m;j+=i) pre[j]=1;
    for(int i=2;i<=m;i++)
        if(pre[i]) pre[i]=pre[i-1]; else pre[i]=pre[i-1]+1;
}

int main()
{
    scanf("%d%d",&n,&m);
    sel();
    while(n--)
    {
        scanf("%d%d",&l,&r);
        if(l>m||r>m||l<1||r<1) printf("Crossing the line\n");
        else printf("%d\n",pre[r]-pre[l-1]);
    }
    return 0;
}