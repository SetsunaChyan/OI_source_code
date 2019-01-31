#include <cstdio>
#include <memory.h>
#include <algorithm>

int a[10005],n,sum=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::sort(a,a+n);
    if(a[0]!=1) {printf("1");return 0;}
    for(int i=0;i<n;i++)
    {
        if(sum&&sum+1<a[i]) {printf("%d",sum+1);return 0;}
        sum+=a[i];
    }
    printf("%d",sum+1);
    return 0;
}