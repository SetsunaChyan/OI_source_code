#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[200005];
ll dif[200005];

void cal(int x,int y)
{
    if(x==y) return;
    if(x>y) swap(x,y);
    dif[1]+=(y-x);
    dif[x]-=(y-x);
    dif[x]+=y-1;
    dif[x+1]-=y-1;
    dif[x+1]+=(y-x-1);
    dif[y]-=(y-x-1);
    dif[y]+=x;
    dif[y+1]-=x;
    dif[y+1]+=(y-x);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m-1;i++)
        cal(a[i],a[i+1]);
    for(int i=1;i<=n;i++) dif[i]+=dif[i-1],printf("%lld ",dif[i]);
    return 0;
}
