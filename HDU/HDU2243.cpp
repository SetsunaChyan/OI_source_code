#include <cstdio>
#include <memory>
#include <cstring>
#include <queue>

using namespace std;
typedef unsigned long long ll;
ll e[40][40],ans,xs[40][40];
int n,l,fail[40],sz,hd,nxt[40][26],cnt[40];
char s[10];

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret*=x;
        x*=x;
        y>>=1;
    }
    return ret;
}

void multi(ll x[40][40],ll y[40][40],int n)
{
    ll tmp[40][40];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                tmp[i][j]+=x[i][k]*y[k][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=tmp[i][j];
}

void fp_m(ll x[40][40],ll y,int n)
{
    ll ret[40][40];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<n;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x,n);
        multi(x,x,n);
        y>>=1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=ret[i][j];
}

void trie_insert(int head,char s[],int len)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
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
    fail[head]=1;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<26;i++)
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
    while(~scanf("%d%d",&n,&l))
    {
        sz=1;hd=1;ans=0;
        memset(e,0,sizeof(e));
        memset(fail,0,sizeof(fail));
        memset(nxt,0,sizeof(nxt));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            trie_insert(hd,s,strlen(s));
        }
        acatm_build(hd);
        e[0][0]=1;
        for(int i=1;i<=sz;i++)
        {
            if(cnt[i]) continue;
            e[i][0]=1;
            for(int k=0;k<26;k++)
                if(!cnt[nxt[i][k]]) e[i][nxt[i][k]]++;
        }
        xs[0][0]=xs[0][1]=1,xs[1][0]=0,xs[1][1]=26;
        fp_m(e,l,sz+1);
        fp_m(xs,l+1,2);
        for(int i=0;i<=sz;i++) ans+=e[1][i];
        ans=xs[0][1]-ans;
        printf("%llu\n",ans);
    }
    return 0;
}