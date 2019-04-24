#include <bits/stdc++.h>
using namespace std;

int n,a[1<<21],b[1<<23];

int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        memset(b,0,sizeof(b));
        for(int j=0;j<(2<<i);j++) b[(1<<i)+j]=1;
        for(int j=0;j<(1<<n);j++) a[j]|=(1<<i)*b[j%(4<<i)];
    }
    for(int i=0;i<(1<<n)-1;i++) printf("%d ",a[i]);
    printf("%d",a[(1<<n)-1]);
    return 0;
}