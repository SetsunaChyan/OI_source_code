#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define x first
#define y second

ll a[105][105],tmp[105][105];
int n,m,k;
set<int> s;

inline pii up(pii p){return {(p.x-1+n)%n,p.y};}
inline pii down(pii p){return {(p.x+1)%n,p.y};}
inline pii left(pii p){return {p.x,(p.y-1+m)%m};}
inline pii right(pii p){return {p.x,(p.y+1)%m};}
inline ll get(pii p){return a[p.x][p.y];}

void solve()
{
    pii p,now;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            ll t=0;
            now={i,j};
            t+=get(now);
            t+=get(up(now));
            t+=get(down(now));
            t+=get(left(now));
            t+=get(right(now));
            t+=get(up(left(now)));
            t+=get(down(left(now)));
            t+=get(up(right(now)));
            t+=get(down(right(now)));
            tmp[i][j]=t;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            a[i][j]=tmp[i][j];
}

int main()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    while(k--) solve();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            s.insert(a[i][j]);
    printf("%d",(int)s.size());
    return 0;
}

/*
5 4 1
0 0 1 1 0
0 0 1 1 0
0 0 1 1 0
0 0 1 1 0

3 3 2
1 0 0
0 1 0
0 1 0
*/
