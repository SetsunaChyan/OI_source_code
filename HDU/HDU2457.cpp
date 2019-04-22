#include <cstdio>
#include <cstring>
#include <queue>
#include <memory.h>

using namespace std;

int n,hd,sz,nxt[2005][4],cnt[2005],fail[2005],dp[1005][2005];
char s[1005];

inline int max(int a,int b){return a>b?a:b;}

int getval(char x)
{
    if(x=='A') return 0;
    if(x=='C') return 1;
    if(x=='G') return 2;
    return 3;
}

void clear()
{
    hd=sz=1;
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(cnt,0,sizeof(cnt));
    memset(dp,-1,sizeof(dp));
}

void trie_insert(int head,char s[],int len)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=getval(s[i]);
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    cnt[p]=1;
}

void acatm_build(int head)
{
    queue<int> q;
    q.push(head);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
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

void solve(int _)
{
    clear();
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s));
    }
    acatm_build(hd);
    scanf("%s",s);
    int l=strlen(s),ans=0;
    dp[0][1]=0;
    for(int i=0;i<l;i++)
        for(int j=1;j<=sz;j++)
        {
            if(dp[i][j]==-1) continue;
            for(int k=0;k<4;k++)
            {
                if(cnt[nxt[j][k]]) continue;
                if(k==getval(s[i])) 
                    dp[i+1][nxt[j][k]]=max(dp[i][j]+1,dp[i+1][nxt[j][k]]);
                else
                    dp[i+1][nxt[j][k]]=max(dp[i][j],dp[i+1][nxt[j][k]]);
            }    
        }
    for(int i=1;i<=sz;i++)
        ans=max(ans,dp[l][i]);
    if(ans==0) ans=l+1;
    printf("Case %d: %d\n",_,l-ans);
}

int main()
{
    int t=0;
    while(~scanf("%d",&n)&&n)
        solve(++t);
    return 0;
}