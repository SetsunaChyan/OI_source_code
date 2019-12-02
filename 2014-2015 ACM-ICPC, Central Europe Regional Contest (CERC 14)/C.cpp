#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int st,ed,n;
bool gao(int num)
{
    int l,r,mid=n/num;
    if(num%2)
        l=mid-num/2,r=mid+num/2;
    else
        l=mid-num/2+1,r=mid+num/2;
   //printf("%d %d %d %d\n",num,mid,l,r);
    if(l<1||(ll)r*(r+1)-(ll)l*(l-1)!=n+n)return false;
    st=l,ed=r;
    return true;
}
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        if(n==(n&-n)){puts("IMPOSSIBLE");continue;}
        for(int i=2;i*i<=n+n;i++)
            if(gao(i))
            {
                printf("%d =",n);
                for(int i=st;i<=ed;i++)
                    printf("%s%d",i==st?" ":" + ",i);
                puts("");
                break;
            }
    }
    return 0;
}
