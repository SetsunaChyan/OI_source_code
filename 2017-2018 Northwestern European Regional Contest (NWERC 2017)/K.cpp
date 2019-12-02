#include <bits/stdc++.h>
using namespace std;

int n,a[5000],tot;
map<int,double> pid[5000<<2];

void get(int rt)
{
    if((rt<<1)>2*n-1)
    {
        pid[rt][++tot]=1;
        return;
    }
    get(rt<<1),get(rt<<1|1);
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

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    swap(a[1],a[n]);
    sort(a+1,a+n,greater<int>());
    get(1);
    printf("%.10f",pid[1][n]);
    return 0;
}

/*

*/
