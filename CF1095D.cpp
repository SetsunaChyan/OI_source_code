#include <cstdio>

const int maxn=2e5+50;
int a1[maxn],a2[maxn],nxt[maxn],n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a1[i],&a2[i]);
    for(int i=1;i<=n;i++)
    {
        int p=a1[i];
        if(a1[p]==a2[i]||a2[p]==a2[i])
            nxt[i]=p;
        else
            nxt[i]=a2[i];
    }
    if(n!=3)
    {
        int p=1;
        for(int i=0;i<n;i++)
        {
            printf("%d ",p);
            p=nxt[p];
        }
    }
    else
        printf("1 2 3");
    return 0;
}