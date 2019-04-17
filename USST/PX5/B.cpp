#include <cstdio>

int l,n,x,ans1=0,ans2=0;

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
    scanf("%d%d",&l,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        ans1=max(ans1,min(l+1-x,x));
        ans2=max(ans2,max(l+1-x,x));
    }
    printf("%d %d",ans1,ans2);
    return 0;
}