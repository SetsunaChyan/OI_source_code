#include <bits/stdc++.h>
using namespace std;

int n,cnt,a[200005],b[200005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        if(a[i]&1)
        {
            cnt++;
            if(a[i]>0) b[i]=a[i]/2; else b[i]=a[i]/2-1;
        }
        else b[i]=a[i]/2;
    }
    for(int i=0;i<n;i++)
    {
        if(cnt==0) break;
        if(a[i]&1)
        {
            b[i]++;
            cnt-=2;
        }
    }
    for(int i=0;i<n;i++) printf("%d\n",b[i]);
    return 0;
}
