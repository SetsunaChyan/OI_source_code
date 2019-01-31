#include <cstdio>
#include <algorithm>

int n,b,a[20005];

int main()
{
    scanf("%d%d",&n,&b);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::sort(a,a+n);
    int tot=0,sel=0;
    for(int i=n-1;i>=0;i--)
    {
        sel++;
        tot+=a[i];
        if(tot>=b) break;
    }
    printf("%d",sel);
    return 0;
}