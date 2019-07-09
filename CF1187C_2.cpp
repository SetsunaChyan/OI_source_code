#include <bits/stdc++.h>
using namespace std;

int l[1005],r[1005],t[1005],n,m,a[1005];
struct op
{
    int l,r,t;
}e[1005];

bool check(int l,int r)
{
    for(int i=l+1;i<=r;i++)
        if(a[i]<a[i-1]) return true;
    return false;
}

bool cmp(op a,op b)
{
    if(a.l!=b.l) return a.l<b.l;
    return a.r<b.r;
}

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) a[i]=n+1-i;
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&e[i].t,&e[i].l,&e[i].r);
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++)
    {
        if(e[i].t)
        {
            for(int j=e[i].l+1;j<=e[i].r;j++)
                a[j]=a[j-1]+1;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(!e[i].t&&!check(e[i].l,e[i].r))
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}

/*
10 10
1 9 10
1 8 9
1 7 8
1 4 5
1 2 3
1 1 2
0 1 10
0 4 6
0 1 10
0 1 10


*/
