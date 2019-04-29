#include <bits/stdc++.h>
using namespace std;

int n,m,oc=0,ok=0;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        oc+=x&1;
    }
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        ok+=x&1;
    }
    printf("%d",min(oc,m-ok)+min(n-oc,ok));
    return 0;
}