#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    srand(time(0));
    int p[12],org[12],rev[12],qaq[12];
    double ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) org[i]=rand()%10000+1;
    for(int i=1;i<=n;i++) p[i]=i;
    do
    {
        for(int i=1;i<=n;i++) a[i]=org[p[i]],rev[p[i]]=i;
        for(int i=1;i<=500;i++) pid[i].clear();
        get(1,1,n);
        if(pid[1][rev[1]]>ans)
        {
            ans=pid[1][rev[1]];
            for(int i=1;i<=n;i++) qaq[i]=a[i];
        }
    }while(next_permutation(p+1,p+n+1));

    for(int i=1;i<=500;i++) pid[i].clear();
    for(int i=1;i<=n;i++) printf("%d ",org[i]);
    for(int i=1;i<=n;i++) a[i]=org[i];
    swap(a[1],a[n]);
    sort(a+1,a+n,greater<int>());
    get(1,1,n);
    printf("\nmy: %.10f\n",pid[1][n]);
    printf("\ndif: %.10f\n",pid[1][n]-ans);
    printf("\n%.10f\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",qaq[i]);
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
8 9 1 7 6 7
0.3167044596
*/

