#include <bits/stdc++.h>
using namespace std;

int a[55],b[55],c[55],n,suf[55];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+c[i];
    a[n-1]=b[n-1]=c[n-1];
    for(int i=n-2;i>=0;i--)
    {
        a[i]=max(suf[i+1]-b[i+1]+c[i],a[i+1]);
        b[i]=max(suf[i+1]-a[i+1]+c[i],b[i+1]);
    }
    printf("%d %d",suf[0]-a[0],a[0]);
    return 0;
}

