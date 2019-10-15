#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int fs[]={500,1000,1500,2000,2500,3000};
int n,cnt[5],gaochou[5],ans=0x3f3f3f3f,ti[120][5];

int cal(int x)
{
    int ret=0;
    for(int i=0;i<5;i++)
        if(ti[x][i]!=-1) ret+=fs[gaochou[i]]-fs[gaochou[i]]/250*ti[x][i];
    return ret;
}

int get(ll pass,ll all)
{
    double p=double(pass)/(pass+all);
    if(p<=1/32.0) return 5;
    if(p<=1/16.0) return 4;
    if(p<=1/8.0) return 3;
    if(p<=1/4.0) return 2;
    if(p<=1/2.0) return 1;
    return 0;
}

bool check(ll x)
{
    for(int i=0;i<5;i++)
    {
        if(ti[0][i]==-1&&get(cnt[i],n+x)!=gaochou[i]) return false;
        else if(get(cnt[i],n+x)<gaochou[i]||get(cnt[i]+x,n+x)>gaochou[i]) return false;
    }
    return true;
}

void dfs(int now)
{
    if(now==5)
    {
        ll l=0,r=1e9+7;
        while(l<r)
        {
            ll mid=l+r>>1;
            if(check(mid)) r=mid; else l=mid+1;
        }
        if(!check(l)) return;
        if(cal(0)>cal(1)) ans=min((long long)ans,l);
        return;
    }
    for(int i=0;i<=5;i++)
        gaochou[now]=i,dfs(now+1);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
        {
            scanf("%d",&ti[i][j]);
            if(ti[i][j]!=-1) cnt[j]++;
        }
    dfs(0);
    if(ans==0x3f3f3f3f) printf("-1"); else printf("%d",ans);
    return 0;
}
