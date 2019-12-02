#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,l[10],a[10];
ll dp[10][2000];
vector<vector<int>> v[10];

void dfs(int now,int len)
{
    if(now==len)
    {
        int flag=1;
        for(int i=0;i<len-1;i++)
            if(a[i+1]<a[i]) flag=0;
        if(flag)
        {
            vector<int> tmp;
            for(int i=0;i<len;i++) tmp.push_back(a[i]);
            v[len].push_back(tmp);
        }
        return;
    }
    for(int i=1;i<=k;i++)
        a[now]=i,dfs(now+1,len);
}

bool check(vector<int> &v,vector<int> &u)
{
    for(int i=0;i<u.size();i++)
        if(v[i]>=u[i]) return false;
    return true;
}

void solve()
{
    for(int i=1;i<=n;i++) scanf("%d",l+i);
    scanf("%d",&k);
    for(int i=l[n];i<=l[1];i++) v[i].clear(),dfs(0,i);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<v[l[1]].size();i++) dp[1][i]=1;
    for(int i=2,j,g;i<=n;i++)
    {
        j=0;
        for(auto &uu:v[l[i]])
        {
            g=0;
            for(auto &vv:v[l[i-1]])
            {
                if(check(vv,uu)) dp[i][j]+=dp[i-1][g];
                g++;
            }
            j++;
        }
    }
    ll ans=0;
    for(int i=0;i<v[l[n]].size();i++) ans+=dp[n][i];
    /*printf("---------- %d\n",v[1].size());
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[l[i]].size();j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }*/
    printf("%lld\n",ans);
}

int main()
{
    //scanf("%d",&n);
    //n=7;
    //for(int i=1;i<=7;i++) l[i]=7;
    //k=7;
    //solve();
    while(~scanf("%d",&n)) solve();
    return 0;
}
/*
7 7 7 7 7 7 7 7
7
*/
