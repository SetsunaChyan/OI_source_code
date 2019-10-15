#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,flag;
char m[2][200005];

void dfs(int x,int y,int lx,int ly)
{
    if(x==0&&y==n) return;
    if(x==1&&y==n)
    {
        flag=1;
        return;
    }
    if(m[x][y]=='1'||m[x][y]=='2')
    {
        if(x==lx) dfs(x,y+1,x,y);
    }
    else
    {
        if(x!=lx) dfs(x,y+1,x,y);
        else dfs(x^1,y,x,y);
    }
}

void solve()
{
    flag=0;
    scanf("%d",&n);
    scanf("%s%s",m[0],m[1]);
    dfs(0,0,0,-1);
    if(flag) printf("YES\n"); else printf("NO\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
