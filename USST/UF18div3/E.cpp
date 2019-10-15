#include <bits/stdc++.h>
using namespace std;

int n,m,k,pre[200005];

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0,l,r;i<n;i++)
        scanf("%d%d",&l,&r),pre[l]++,pre[r+1]--;
    for(int i=1;i<=200000;i++) pre[i]+=pre[i-1];
    for(int i=1;i<=200000;i++) pre[i]=pre[i]>=k?1:0;
    for(int i=1;i<=200000;i++) pre[i]+=pre[i-1];
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",pre[r]-pre[l-1]);
    }
    return 0;
}
