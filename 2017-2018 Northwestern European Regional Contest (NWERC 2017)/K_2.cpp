#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[5000];
map<int,double> pid[5000<<2];

void get(int rt,int l,int r)
{
    if(l==r)
    {
        pid[rt][l]=1;
        return;
    }
    int m=l+r>>1;
    get(rt<<1,l,m),get(rt<<1|1,m+1,r);
    for(auto &pl:pid[rt<<1])
    {
        int ll=a[pl.first],rr;
        for(auto &pr:pid[rt<<1|1])
        {
            rr=a[pr.first];
            pid[rt][pl.first]+=pl.second*pr.second*ll/(ll+rr);
            pid[rt][pr.first]+=pl.second*pr.second*rr/(ll+rr);
        }
    }
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    swap(a[1],a[n]);
    sort(a+1,a+n,greater<int>());
    get(1,1,n);
    printf("%.10f",pid[1][n]);
    return 0;
}

/*
4
8 8 9 9
0.2647058824

4
8 9 8 9
0.1908209438

6
1 3 4 7 10 4
0.1709633464

6
1 3 4 10 7 4
*/
