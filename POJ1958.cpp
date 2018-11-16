#include <cstdio>
#include <memory.h>

int f[13];
inline int min(int a,int b){return a<b?a:b;}

int main()
{
    memset(f,0x3f,sizeof(f));
    f[1]=1;f[0]=0;
    for(int n=2;n<=12;n++)
    {
        for(int i=1;i<n;i++)
            f[n]=min(f[n],2*f[i]+(1<<(n-i))-1);
    }
    for(int i=1;i<=12;i++) printf("%d\n",f[i]);
    return 0;
}
