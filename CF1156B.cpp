#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26],vis[26],sel[26],flag,tot;
char s[1000],ans[1000];

void dfs(int dep,int last)
{
    if(dep==tot)
    {
        for(int i=0;i<dep;i++)
            for(int j=0;j<cnt[sel[i]];j++)
                printf("%c",sel[i]+'a');
        printf("\n");
        flag=1;
        return;
    }
    for(int i=0;i<26;i++)
    {
        if(!vis[i]&&i!=last+1&&i!=last-1)
        {
            vis[i]=1;
            sel[dep]=i;
            dfs(dep+1,i);
            if(flag) return;
            vis[i]=0;
        }
    }
}

void solve()
{
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    tot=26,flag=0;
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++;
    for(int i=0;i<26;i++) 
        if(!cnt[i]) vis[i]=1,tot--;
    dfs(0,-2);
    if(!flag) printf("No answer\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}