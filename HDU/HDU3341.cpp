#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,hd,sz,nxt[605][4],fail[605],cnt[605],A,C,T,G,l,ans,dp[605][15000],mp[41][41][41][41],hashsz;
char s[55];

inline char getval(char x)
{
    if(x=='A') return 0;
    if(x=='C') return 1;
    if(x=='T') return 2;
    return 3;
}

void clear()
{
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(dp,-1,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    memset(mp,0,sizeof(mp));
    A=C=T=G=ans=hashsz=0,hd=sz=1;
    dp[1][0]=0;
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
    cnt[p]++;
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
                fail[nxt[p][i]]=head==p?head:nxt[fail[p]][i];
                cnt[nxt[p][i]]+=cnt[fail[nxt[p][i]]];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=head==p?head:nxt[fail[p]][i];
    }
}

void solve(int cs)
{
    clear();
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s));
    }
    acatm_build(hd);
    scanf("%s",s);
    l=strlen(s);
    for(int i=0;i<l;i++)
        if(s[i]=='A') A++;
        else if(s[i]=='C') C++;
        else if(s[i]=='T') T++;
        else G++;
    for(int i=0;i<=A;i++)
        for(int j=0;j<=C;j++)
            for(int k=0;k<=T;k++)
                for(int m=0;m<=G;m++)
                    mp[i][j][k][m]=hashsz++;
    for(int a=0;a<=A;a++)
        for(int c=0;c<=C;c++)
            for(int t=0;t<=T;t++)
                for(int g=0;g<=G;g++)
                    for(int j=1;j<=sz;j++)
                        for(int k=0;k<4;k++)
                        {
                            if(a==A&&k==0||c==C&&k==1||t==T&&k==2||g==G&&k==3) continue;
                            if(dp[j][mp[a][c][t][g]]==-1) continue;
                            int &p=dp[nxt[j][k]][mp[a+(k==0)][c+(k==1)][t+(k==2)][g+(k==3)]];
                            p=max(p,dp[j][mp[a][c][t][g]]+cnt[nxt[j][k]]);
                        }
    for(int i=1;i<=sz;i++)
        ans=max(ans,dp[i][mp[A][C][T][G]]);
    printf("Case %d: %d\n",cs,ans);
}

int main()
{
    int cs=0;
    while(~scanf("%d",&n)&&n)
        solve(++cs);
    return 0;
}