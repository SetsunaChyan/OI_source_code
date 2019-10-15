#include <bits/stdc++.h>
using namespace std;

int n,a[1000],cnt,vis[1000];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        cnt++;
        for(int j=0;j<n;j++)
            if(a[j]%a[i]==0) vis[j]=1;
    }
    printf("%d",cnt);
    return 0;
}
