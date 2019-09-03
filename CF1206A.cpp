#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a=0,b=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a=max(a,x);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        b=max(b,x);
    }
    printf("%d %d",a,b);
    return 0;
}
