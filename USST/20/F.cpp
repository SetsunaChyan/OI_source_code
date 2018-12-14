#include <cstdio>

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
    int n,a[120],ans=0x3f3f3f3f,k=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        k=max(a[i]-a[i-1],k);
    for(int i=2;i<n;i++)
        ans=min(ans,max(k,a[i]-a[i-2]));
    printf("%d",ans);
    return 0;
}