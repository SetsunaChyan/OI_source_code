#include <cstdio>

int n,a[105],w2=0x3f3f3f3f,w1=0;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i) w1=max(w1,a[i]-a[i-1]);
    }
    for(int i=2;i<n;i++)
        w2=min(w2,a[i]-a[i-2]);
    printf("%d",max(w1,w2));
    return 0;
}