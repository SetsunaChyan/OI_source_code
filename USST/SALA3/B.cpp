#include <bits/stdc++.h>
using namespace std;

int n,a[200005],pre[200005][2];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        pre[i][1]=pre[i-1][1];
        pre[i][0]=pre[i-1][0];
        if(i&1) pre[i][1]+=a[i];
        else pre[i][0]+=a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int odd=pre[i-1][1]+pre[n][0]-pre[i][0];
        int even=pre[i-1][0]+pre[n][1]-pre[i][1];
        //printf("%d %d %d\n",i,odd,even);
        if(odd==even) cnt++;
    }
    printf("%d",cnt);
    return 0;
}

