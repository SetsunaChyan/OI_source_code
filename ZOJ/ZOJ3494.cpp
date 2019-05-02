#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+9;
int n,fail[10000],nxt[10000][10],cnt[10000],a[300],sz;
ll dp[300][10000];
char tmp[300],l[300],r[300];
queue<int> q;

ll dfs(int p,int pre,bool leadzero,bool limit)
{
    if(p==-1) return 1;
    if(~dp[p][pre]&&!limit&&!leadzero) return dp[p][pre];
    ll ret=0;
    int n=limit?a[p]:9;
    for(int i=0;i<=n;i++)
    {
        if(!leadzero||i!=0)
            if(cnt[nxt[pre][i]]) continue;
        int pp=nxt[pre][i];
        if(leadzero&&i==0) pp=1;
        ret=(ret+dfs(p-1,pp,leadzero&&i==0,limit&&a[p]==i))%mod;
    }
    if(!limit&&!leadzero) dp[p][pre]=ret;
    return ret;
}

ll cal(char num[],int len)
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<len;i++)
        a[i]=num[len-i-1]-'0';
    return dfs(len-1,1,true,true);
}

void clear()
{
    sz=1;
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(cnt,0,sizeof(cnt));
}

void trie_insert(int s[],int len)
{
    for(int i=0;i<len;i+=4)
    {
        int k=s[i]*8+s[i+1]*4+s[i+2]*2+s[i+3];
        if(k>9) return;
    }
    int p=1;
    for(int i=0;i<len;i+=4)
    {
        int k=s[i]*8+s[i+1]*4+s[i+2]*2+s[i+3];
        if(!nxt[p][k]) nxt[p][k]=++sz;
        p=nxt[p][k];
    }
    cnt[p]=1;
}

void com(char s[],int block,int len)
{
    int num[30],g;
    g=4-(block+len)%4+block;
    if((block+len)%4==0) g-=4;
    for(int i=block;i<block+len;i++)
        num[i]=s[i-block]-'0';
    for(int i=0;i<(1<<g);i++)
    {
        int tmp=i;
        int cnt=0;
        for(int j=0;j<block;j++)
        {
            num[j]=tmp&1;
            tmp>>=1;
            cnt++;
        }
        for(int j=block+len;j<len+g;j++)
        {
            num[j]=tmp&1;
            tmp>>=1;
            cnt++;
        }
        trie_insert(num,g+len);
    }
}

void acatm_build()
{
    while(!q.empty()) q.pop();
    q.push(1);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<10;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=p==1?1:nxt[fail[p]][i];
                cnt[nxt[p][i]]|=cnt[fail[nxt[p][i]]];
                q.push(nxt[p][i]);
            }
            else 
                nxt[p][i]=p==1?1:nxt[fail[p]][i];
    }
}

void solve()
{
    clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",tmp);
        int len=strlen(tmp);
        for(int j=0;j<4;j++)
            com(tmp,j,len);
    }
    scanf("%s%s",l,r);
    int len=strlen(l);
    l[len-1]-=1;
    for(int i=len-1;i>0;i--)
        if(l[i]<'0') 
        {
            l[i]+=10;
            l[i-1]--;
        }
        else break;
    acatm_build();
    printf("%lld\n",(cal(r,strlen(r))-cal(l,strlen(l))+mod)%mod);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}