#include <cstdio>
#include <cstring>
#include <memory>
#include <queue>

using namespace std;

typedef long long ll;

class bigint
{
    private:
        static const int n=50;
        static const ll mod=10000;
        ll x[n]; //压4位
    public:
        bigint()
        {
            memset(x,0,sizeof(x));
        }
        bigint(ll y)
        {
            memset(x,0,sizeof(x));
            x[n-1]=y;   
            for(int i=n-1;i;i--)
            {
                x[i-1]+=x[i]/mod;
                x[i]%=mod;
            }
        }
        void printnum()
        {
            int i;
            for(i=0;i<n-1;i++)
                if(x[i]) break;
            printf("%lld",x[i]);
            for(i=i+1;i<n;i++)  
                printf("%04lld",x[i]);
        }
        bigint operator + (const bigint r)
        {
            bigint ret;
            for(int i=n-1;i>=0;i--)
                ret.x[i]=x[i]+r.x[i];
            for(int i=n-1;i;i--)
            {
                ret.x[i-1]+=ret.x[i]/mod;
                ret.x[i]%=mod;
            }   
            return ret;
        }
        bigint operator = (const bigint r)
        {
            for(int i=0;i<n;i++)
                this->x[i]=r.x[i];
            return *this;
        }
        bigint operator = (const ll r)
        {
            bigint ret(r);
            for(int i=0;i<n;i++)
                this->x[i]=ret.x[i];
            return *this;
        }
        bigint& operator ++ ()
        {
            this->x[n-1]++;
            for(int i=n-1;i;i--)
            {
                this->x[i-1]+=this->x[i]/mod;
                this->x[i]%=mod;
            }
            return *this; 
        }
};

int hd=1,sz=1,fail[205],nxt[205][55],cnt[205],n,m,p,abt[256];
char s[200];
bigint ans,dp[205][55];

void trie_insert(int head,char s[],int len)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=abt[s[i]];
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    cnt[p]=1;
}

void acatm_build(int head)
{
    int p;
    queue<int> q;
    q.push(head);
    fail[head]=head;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<n;i++)
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

int main()
{
    memset(fail,0,sizeof(fail));
    memset(nxt,0,sizeof(nxt));
    memset(cnt,0,sizeof(cnt));
    memset(abt,0,sizeof(abt));
    scanf("%d%d%d ",&n,&m,&p);
    for(int i=0;i<n;i++)
    {
        char c;
        scanf("%c",&c);
        abt[c]=i;
    }
    for(int i=0;i<p;i++)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s));
    }
    acatm_build(hd);
    
    dp[1][0]=1;
    for(int t=1;t<=m;t++)
        for(int i=1;i<=sz;i++)
        {
            if(cnt[i]) continue;
            for(int j=0;j<n;j++)
                if(!cnt[nxt[i][j]]) dp[nxt[i][j]][t]=dp[nxt[i][j]][t]+dp[i][t-1];
        }
    for(int i=1;i<=sz;i++)
        ans=ans+dp[i][m];
    ans.printnum();
    return 0;
}