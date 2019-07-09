#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100005;
ll bit[MAXN],ans[MAXN];
int op[MAXN],opl[MAXN],opr[MAXN],n,m;

void add(int x,ll y){for(;x<=m+1;x+=x&-x) bit[x]+=y;}
ll sum(int x){ll ret=0;for(;x;x-=x&-x) ret+=bit[x];return ret;}

int main()
{
    memset(bit,0,sizeof(bit));
    memset(ans,0,sizeof(ans));
    scanf("%d%d",&n,&m);
    add(1,1);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&op[i],&opl[i],&opr[i]);
    for(int i=m;i;i--)
    {
        ll k=sum(i);
        if(op[i]==2)
        {
            add(opr[i]+1,-k);
            add(opl[i],k);
        }
        else
            ans[opr[i]+1]-=k,ans[opl[i]]+=k;
    }
    ll x=0;
    for(int i=1;i<=n;i++)
        printf("%d ",x+=ans[i]);
    return 0;
}
