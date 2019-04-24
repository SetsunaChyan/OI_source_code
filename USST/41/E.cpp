#include <bits/stdc++.h>
using namespace std;

int q[1000005],a[1000005],n,k,hd=0,ed=0;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        while(hd<ed&&a[q[ed-1]]<a[i]) ed--;
        q[ed++]=i;
        while(hd<ed&&i-q[hd]>=k) hd++;
        if(i>=k-1) printf("%d %d\n",a[q[hd]],q[hd]+1);
    }
    return 0;
}