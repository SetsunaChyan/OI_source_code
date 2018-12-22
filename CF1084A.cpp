#include <cstdio>

int n,a[105],ans=0x3f3f3f3f;

inline int abs(int x){return x>0?x:-x;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<n;j++)
            temp+=2ll*a[j]*(j+i+abs(j-i));
        ans=min(ans,temp);
    }
    printf("%d",ans);
    return 0;
}