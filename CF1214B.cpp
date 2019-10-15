#include <bits/stdc++.h>
using namespace std;

int b,g,n,ans;

int main()
{
    scanf("%d%d%d",&b,&g,&n);
    for(int i=0;i<=n;i++)
        if(i<=b&&(n-i)<=g) ans++;
    printf("%d",ans);
    return 0;
}
