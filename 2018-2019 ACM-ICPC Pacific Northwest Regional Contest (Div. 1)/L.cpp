#include <bits/stdc++.h>
using namespace std;
int n,a[1004],b[1004];
bool ok(int x)
{
    int c=0;
    for(int i=1;i<=n;i++)c+=x>=a[i]&&x<=b[i];
    return c==x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",a+i,b+i);
    int i;
    for(i=n;i>=0;i--)
        if(ok(i))
            break;
    printf("%d\n",i);
    return 0;
}
