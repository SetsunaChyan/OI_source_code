#include <cstdio>
#include <memory.h>

int ans=0,minx[5],n;

inline int min(int a,int b){return a<b?a:b;}

int main()
{
    memset(minx,0,sizeof(minx));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a[5],s=0;
        for(int j=0;j<5;j++)
        {
            scanf("%d",&a[j]);
            s+=a[j];
            minx[j]+=a[j];
        }
        if(s>=5) ans++;
    }
    for(int i=0;i<5;i++)
        minx[0]=min(minx[0],minx[i]);
    printf("%d",min(minx[0],ans));
    return 0;
}