#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,vis[30],g[30],cnt[30],mp[30][30];
char s[1000005];

void dfs(int now)
{
    vis[now]=1;
    for(int i=0;i<26;i++)
        if(!vis[i]&&mp[i][now]) dfs(i);
}

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s);
        int l=strlen(s);
        for(int j=0;j<l;j++) cnt[s[j]-'a']++,g[s[j]-'a']++;
        for(int j=0;j<26;j++)
            if(cnt[j])
                for(int k=j+1;k<26;k++)
                    if(cnt[k]) mp[j][k]=mp[k][j]=1;
    }
    int ans=0;
    for(int i=0;i<26;i++) if(!vis[i]&&g[i]) dfs(i),ans++;
    printf("%d",ans);
}

int main()
{
    int _=1;
    //scanf("%d",&_);
    while(_--) solve();
    return 0;
}
