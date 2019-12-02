#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k,vis[26][26],pre[26];
ll ans;
char a[100005],b[100005];

void gao()
{
    ans=0;
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre));
    scanf("%d%d%d%s%s",&n,&m,&k,a,b);
    for(int i=0;i<n-k+1;i++)
        vis[a[i]-'a'][a[i+k-1]-'a']++;
    for(int i=0;i<m;i++)
    {
        int now=b[i]-'a';
        pre[now]++;
        for(int j=0;j<26;j++)
            if(vis[j][now]) ans+=pre[j];
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) gao();
    return 0;
}
