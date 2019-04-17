#include <cstdio>
#include <algorithm>

using namespace std;

int h,n,a[10005],b[10005],c[10005];

int main()
{
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=n;j++)
    {
        int flag=0,ttt=0,hh=h,tot=0;
        for(int i=0;i<j;i++)
            b[i]=a[i];
        sort(b,b+j);
        for(int i=j-1;i>0;i-=2)
            if(hh>=b[i]) hh-=b[i]; else {ttt=1;break;}
        if(j&1) if(hh<b[0]) ttt=1;
        if(ttt) {printf("%d",j-1);return 0;}
    }
    printf("%d",n);
    return 0;
}