#include <cstdio>
#include <cstring>
#include <memory.h>
#include <queue>

using namespace std;

int fail[2005],nxt[2005][26],cnt[2005],sz,hd,n,m,dp[55][2005],from[55][2005],ch[2005],vis[55][2005],sel[55][2005];
char s[105][15];

inline void clear()
{
    sz=hd=1;
    memset(vis,0,sizeof(vis));
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
        ch[p]=c;
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

void print(int x,int y)
{
    if(x>1) print(x-1,from[x][y]);
    if(x) printf("%c",sel[x][y]+'a');
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

    int ans=0,idi=0,idj=1;
    queue<pair<int,int> > q;
    dp[0][1]=0,vis[0][1]=1;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int i=q.front().first,j=q.front().second;
        q.pop();
        if(dp[i][j]<0) continue;
        for(int k=0;k<26;k++)
            if(nxt[j][k]!=hd&&dp[i][j]+cnt[nxt[j][k]]>dp[i+1][nxt[j][k]])
            {
                dp[i+1][nxt[j][k]]=dp[i][j]+cnt[nxt[j][k]];
                from[i+1][nxt[j][k]]=j;
                sel[i+1][nxt[j][k]]=k;
                if(ans<dp[i+1][nxt[j][k]])
                {
                    ans=dp[i+1][nxt[j][k]];
                    idi=i+1;
                    idj=nxt[j][k];
                }
                if(i+1==n)
                {
                    print(i+1,nxt[j][k]);
                    puts("");
                }
                if(!vis[i+1][nxt[j][k]]&&i+1<n) 
                {
                    q.push(make_pair(i+1,nxt[j][k]));

                        print(i,j);
                        printf(" ");
                        print(i+1,nxt[j][k]);
                        puts("");

                    vis[i+1][nxt[j][k]]=1;
                }
            }
    }
    print(idi,idj);
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

/*
4
4 10
ab
ac
ad
ae
af
ba
bb
bc
bd
be
1 1 1 1 1 1 1 1 1 1
*/