#include <bits/stdc++.h>
using namespace std;

int mp[105][105],n,m,now,a[1000005],des,dp[105][105][105];
vector<int> ans;

void solve(int l,int r)
{
    if(l==r)
    {
        ans.push_back(a[l]);
        return;
    }
    des=a[r];
    now=a[l];
    if(des==now)
    {
        ans.push_back(now);
        solve(l+1,r-1);
        ans.push_back(des);
        return;
    }
    ans.push_back(now);
    for(int i=1;i<m-1;i++)
    {
        if(mp[now][a[i]]+mp[a[i]][des]==mp[now][des])
        {
            if(now==des&&a[i+1]!=m||now!=des) continue;
        }
        now=a[i];
        ans.push_back(a[i]);
    }
    ans.push_back(des);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%1d",&mp[i][j]);
            if(!mp[i][j]) mp[i][j]=0x3f3f3f3f;
        }
    for(int i=1;i<=n;i++)
        mp[i][i]=0x3f3f3f3f;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				dp[i][j][k]=(mp[i][k]+mp[k][j]==mp[i][j]);
				if(i==j) dp[i][j][k]=0;
			}
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    des=a[m-1];
    now=a[0];
    ans.push_back(now);
    for(int i=1;i<m-1;i++)
		if(dp[now][a[i+1]][a[i]]) now=a[i-1]; else now=a[i],ans.push_back(now);
    ans.push_back(des);
    printf("%d\n",ans.size());
    for(auto k:ans) printf("%d ",k);
    return 0;
}
