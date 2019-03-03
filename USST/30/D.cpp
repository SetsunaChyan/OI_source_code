#include <cstdio>

const int INF=0x3f3f3f3f;
int n,a[300005],pre[300005],suf[300005],ans1=0,ans2=0;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[0]=-INF,a[n+1]=INF;
    pre[0]=0,suf[n+1]=0;
    for(int i=1;i<=n;i++)
        if(a[i]>a[i-1])
            pre[i]=pre[i-1]+1;
        else
            pre[i]=1;
    for(int i=n;i>0;i--)
        if(a[i]<a[i+1])
            suf[i]=suf[i+1]+1;
        else
            suf[i]=1;
    for(int i=1;i<=n;i++)
    {
        ans1=max(ans1,pre[i]);
        if(a[i-1]+1<a[i+1])
            ans2=max(ans2,pre[i-1]+suf[i+1]+1);
    }
    ans2=max(min(n,ans1+1),ans2);
    printf("%d\n%d",ans1,ans2);
    return 0;
}