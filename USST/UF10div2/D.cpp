#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge
{
    int x1,y1,x2,y2;
}e[100005];
int n,m,l,r,x[100005],y[100005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d%d",x+i,y+i);
    for(int i=0;i<n;i++)
    {
        e[i].x1=x[i],e[i].y1=y[i];
        if(i!=n-1) e[i].x2=x[i+1],e[i].x3=
    }
    return 0;
}
