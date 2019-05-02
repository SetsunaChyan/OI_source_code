#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q[200005],z,hd=0,ed=0,a[200005],ans=0;

int main()
{
    scanf("%d%d",&n,&z);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(hd!=ed&&a[q[hd]]+z<=a[i]) 
        {
            //printf("%d %d\n",a[q[hd]],a[i]);
            ans++,hd++;
            continue;
        }
        q[ed++]=i;
    }
    printf("%d",ans);
    return 0;
}