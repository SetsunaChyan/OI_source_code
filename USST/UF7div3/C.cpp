#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sol,pen;
}p[100];
int ss,pp,cnt,n,k;

bool cmp(node a,node b)
{
    if(a.sol==b.sol) return a.pen<b.pen;
    return a.sol>b.sol;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].sol,&p[i].pen);
    sort(p,p+n,cmp);
    ss=p[k-1].sol,pp=p[k-1].pen;
    for(int i=0;i<n;i++)
        if(ss==p[i].sol&&pp==p[i].pen) cnt++;
    printf("%d",cnt);
    return 0;
}
