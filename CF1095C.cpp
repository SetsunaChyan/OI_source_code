#include <cstdio>
#include <memory.h>

int cnt[40],p=0,g=0,t,n,k;

int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&k);
    t=n;
    while(t)
    {
        if(t&1) {g++;cnt[p]++;}
        t>>=1;
        p++;
    }
    if(g>k||n<k)
    {
        printf("NO");
        return 0;
    }
    for(int i=39;i>0;i--)
        while(g<k&&cnt[i])
        {
            cnt[i]--;
            cnt[i-1]+=2;
            g++;
        }
    printf("YES\n");
    for(int i=0;i<40;i++)
        for(int j=0;j<cnt[i];j++)
            printf("%d ",1<<i);
    return 0;
}