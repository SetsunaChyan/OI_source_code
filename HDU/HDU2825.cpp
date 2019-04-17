#include <cstdio>
#include <cstring>
#include <memory.h>
#include <queue>

using namespace std;

const int mod=20090717;
int sz=1,hd=1,cnt[200],k,nxt[200][26],fail[200],n,m,dp[30][105][1050];
char s[100];

inline int get(int x)
{
    int ret=0;
    while(x)
    {
        ret+=x&1;
        x>>=1;
    }
    return ret;
}

void clear()
{
    sz=hd=1;
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
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
    cnt[p]=1<<idx;
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
                fail[nxt[p][i]]=head==p?head:nxt[fail[p]][i];
                cnt[nxt[p][i]]|=cnt[fail[nxt[p][i]]];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=head==p?head:nxt[fail[p]][i];
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k)&&(n||m||k))
    {
        clear();
        for(int i=0;i<m;i++)
        {
            scanf("%s",s);
            trie_insert(hd,s,strlen(s),i);
        }
        acatm_build(hd);
        dp[0][1][0]=1;
        for(int i=0;i<n;i++)
            for(int p=1;p<=sz;p++)
                for(int j=0;j<(1<<m);j++)
                    if(dp[i][p][j])
                        for(int x=0;x<26;x++)
                        {
                            //if(j&cnt[nxt[p][x]]) continue;
                            dp[i+1][nxt[p][x]][j|cnt[nxt[p][x]]]+=dp[i][p][j];
                            dp[i+1][nxt[p][x]][j|cnt[nxt[p][x]]]%=mod;
                        }
        int ans=0;
        for(int i=1;i<=sz;i++)
            for(int j=0;j<(1<<m);j++)
                if(get(j)>=k)
                    ans=(ans+dp[n][i][j])%mod;
        printf("%d\n",ans);
    }

    return 0;
}