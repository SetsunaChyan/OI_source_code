#include <cstdio>
#include <cmath>
#include <queue>
#include <memory.h>

using namespace std;

const double INF=1e20;
double dp[55][600],loc[55][2];
int n,m,k,hd,sz,nxt[600][55],fail[600],cnt[600],tmp[10];

inline double min(double a,double b){return a<b?a:b;}

void clear()
{
    hd=sz=1;
    memset(cnt,0,sizeof(cnt));
    memset(fail,0,sizeof(fail));
    memset(nxt,0,sizeof(nxt));
    for(int i=0;i<55;i++)
        for(int j=0;j<600;j++)
            dp[i][j]=INF;
}

void trie_insert(int head,int* s,int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-1;
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    cnt[p]=idx;
}

void acatm_build(int head)
{
    queue<int> q;
    q.push(head);
    while(!q.empty())
    {
        int p=q.front();
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

void solve()
{
    clear();
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&loc[i][0],&loc[i][1]);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
            scanf("%d",&tmp[j]);
        trie_insert(hd,tmp,k,1);
    }
    acatm_build(hd);
    double ans=INF;
    dp[0][nxt[hd][0]]=0;
    for(int i=0;i<n;i++)
        for(int j=1;j<=sz;j++)
        {
            if(dp[i][j]==INF) continue;
            for(int k=i+1;k<n;k++)
            {
                if(cnt[nxt[j][k]]) continue;
                double dis=(loc[i][1]-loc[k][1])*(loc[i][1]-loc[k][1])+(loc[i][0]-loc[k][0])*(loc[i][0]-loc[k][0]);
                dis=sqrt(dis);
                dp[k][nxt[j][k]]=min(dp[k][nxt[j][k]],dp[i][j]+dis);
                if(k==n-1) ans=min(ans,dp[k][nxt[j][k]]);
            }
        }
    if(ans==INF)
        printf("Can not be reached!\n");
    else
        printf("%.2lf\n",ans);
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n&&m) solve();
    return 0;
}