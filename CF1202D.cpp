#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,b,l,r,n;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld",&n);
        l=0;r=1e9;
        while(l<r)
        {
            ll m=l+r>>1;
            if((m+3)*(m+2)/2>=n-1) r=m; else l=m+1;
        }
        b=l;
        c=n-(b+2)*(b+1)/2;
        printf("133");
        for(int i=0;i<c;i++) putchar('7');
        for(int i=0;i<b;i++) putchar('3');
        printf("7\n");
    }
    return 0;
}
