#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;
int n,m,seg[MAXN<<2],lazy[MAXN<<2],dfsord[MAXN],r[MAXN],l[MAXN],head[MAXN];
struct edge
{
    int to,nxt;
}e[MAXN<<1];

void solve(int cs)
{
    memset(lazy,-1,sizeof(lazy));
    scanf("%d",&n);
    build(1,1,n);
    printf("Case #%d:\n",cs);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=0;i<n;i++)
        {
            
        }
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++) solve(i); 
    return 0;
}