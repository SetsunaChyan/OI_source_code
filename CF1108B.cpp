#include <cstdio>
#include <memory.h>

int n,cnt[10005],a=0,b=0;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
        a=max(a,x);
    }
    for(int i=1;i<=10000;i++)
        if(cnt[i]==2||a%i&&cnt[i]==1) b=i;
    printf("%d %d",a,b);
    return 0;
}