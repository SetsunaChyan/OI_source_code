#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("1008t.in","w",stdout);
    printf("3\n");
    for(int T=1;T<=3;T++)
    {
        int n=100000,m=100000;
        printf("%d %d\n",n,m);
        for(int i=1;i<=n;i++)
            printf("%d ",i);
            //printf("%lld ",((ll)rand()*rand())%1000000+1);
        printf("\n");
        for(int i=1;i<=m;i++)
        {
            int l=rand()%n+1,r=rand()%n+1;
            if(l>r) swap(l,r);
            int p=((ll)rand()*rand())%1000000+1;
            int k=rand()%min(r-l+1,169)+1;
            printf("%d %d %d %d\n",l,r,p,k);
        }
    }
    return 0;
}
