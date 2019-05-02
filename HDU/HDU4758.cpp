#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
int n,m,nxt[205][2],fail[205],cnt[205],sz,hd,dp[205][105][105][4];
char s[205];

void clear()
{
    hd=sz=1;
    memset(dp,0,sizeof(dp));
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(cnt,0,sizeof(cnt));
    dp[1][0][0][0]=1;
}

void trie_insert(int head,char s[],int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c;
        if(s[i]=='R') c=0; else c=1;
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    cnt[p]|=idx;
}

void acatm_build(int head)
{
    queue<int> q;
    q.push(head);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<2;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=p==head?head:nxt[fail[p]][i];
                cnt[nxt[p][i]]|=cnt[fail[nxt[p][i]]];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=p==head?head:nxt[fail[p]][i];
    }
}

void solve()
{
    clear();
    scanf("%d%d",&n,&m);
    for(int i=0;i<2;i++)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s),1<<i);
    }
    acatm_build(hd);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int p=1;p<=sz;p++)
                for(int stat=0;stat<4;stat++)
                {
                    if(dp[p][i][j][stat]==0) continue;
                    for(int k=0;k<2;k++)
                    {
                        if(i==n&&k==0||j==m&&k==1) continue;
                        int &res=dp[nxt[p][k]][i+(k==0)][j+(k==1)][stat|cnt[nxt[p][k]]];
                        res+=dp[p][i][j][stat];
                        res%=mod;
                    }
                }
    int ans=0;
    for(int i=1;i<=sz;i++)
        ans=(ans+dp[i][n][m][3])%mod;
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
        solve();
    return 0;
}