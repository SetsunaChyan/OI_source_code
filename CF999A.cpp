#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++)
        if(a[i]<=m) ans++; else break;
    int t=ans;
    for(int i=n-1;i>=t;i--)
        if(a[i]<=m) ans++; else break;
    printf("%d",ans);
    return 0;
}
