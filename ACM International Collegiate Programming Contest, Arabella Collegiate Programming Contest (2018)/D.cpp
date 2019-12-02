#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        if(n/2<=y&&(n+1)/2<=x) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
