#include <cstdio>
#include <memory.h>

int cnt[105],n,m,ans=0;

inline int min(int a,int b){return a<b?a:b;}

int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x%m]++;
    }
    for(int i=1;i<m;i++)
    {
        int k=min(cnt[i],cnt[m-i]);
        if(i!=m-i) ans+=k*2; else ans+=k/2*2;
        cnt[i]-=k;
        cnt[m-i]-=k;
    }
    ans+=cnt[0]/2*2;
    printf("%d",ans);
    return 0;
}