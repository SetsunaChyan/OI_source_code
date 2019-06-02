#include <bits/stdc++.h>
using namespace std;

int a[1000005],n,k;

bool cmp(int a,int b){return a>b;}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        for(int i=0;i<k-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[k-1]);
    }
    return 0;
}
