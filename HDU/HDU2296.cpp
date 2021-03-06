#include <cstdio>
#include <cstring>
#include <memory.h>
#include <queue>
#include <string>

using namespace std;

int fail[2005],nxt[2005][26],cnt[2005],sz,hd,n,m,dp[55][2005],from[55][2005];
char s[105][15];
string dps[55][2005];

void clear()
{
    sz=hd=1;
    memset(dp,0xc0,sizeof(dp));
    memset(fail,0,sizeof(fail));
    memset(nxt,0,sizeof(nxt));
    memset(cnt,0,sizeof(cnt));
}
 
void trie_insert(int head,char s[],int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    cnt[p]+=idx;
}

void acatm_build(int head)
{
    queue<int> q;
    q.push(head);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<26;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=p==head?head:nxt[fail[p]][i];
                cnt[nxt[p][i]]+=cnt[fail[nxt[p][i]]];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=p==head?head:nxt[fail[p]][i];
    }
}

bool scmp(string a,string b)
{
    if(a.length()==b.length()) return a<b;
    else return a.length()<b.length();
}

void solve()
{
    clear();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%s",s[i]);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        trie_insert(hd,s[i],strlen(s[i]),x);
    }
    acatm_build(hd);

    for(int i=0;i<=n;i++)
        for(int j=0;j<=sz;j++)
            dps[i][j]=string("");
    int ans=0;
    string anss;
    queue<pair<int,int> > q;
    dp[0][1]=0;
    for(int i=0;i<n;i++)
        for(int j=1;j<=sz;j++)
            for(int k=0;k<26;k++)
                if(dp[i][j]+cnt[nxt[j][k]]>dp[i+1][nxt[j][k]]
                ||dp[i][j]+cnt[nxt[j][k]]==dp[i+1][nxt[j][k]]&&scmp(dps[i][j]+char('a'+k),dps[i+1][nxt[j][k]]))
                {
                    dps[i+1][nxt[j][k]]=dps[i][j]+char('a'+k);
                    dp[i+1][nxt[j][k]]=dp[i][j]+cnt[nxt[j][k]];
                }
    for(int i=0;i<=n;i++)
        for(int j=1;j<=sz;j++) 
            if(dp[i][j]>ans||dp[i][j]==ans&&scmp(dps[i][j],anss))
            {
                ans=dp[i][j];
                anss=dps[i][j];
            }
    for(int i=0;i<anss.length();i++)
        printf("%c",anss[i]);
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}