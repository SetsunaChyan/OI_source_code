#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string rem,s;
const int MAXN=700005;
int pos=0,maxright=0,maxlen=0,r[700005],last[26];
ll ans;
ll IT[MAXN<<2],add[MAXN<<2];
int n,q;

void mlc()
{
    for(int i=0;i<rem.length();i++)
        s+='#',s+=rem[i];
    s+='#';
    for(int i=0;i<s.length();i++)
    {
        if(i<maxright) r[i]=min(r[2*pos-i],maxright-i);
        else r[i]=1;
        while(i-r[i]>=0&&i+r[i]<s.length()&&s[i-r[i]]==s[i+r[i]]) r[i]++;
        if(r[i]+i-1>maxright)
            maxright=r[i]+i-1,pos=i;
    }
}

void pushup(int rt){IT[rt]=IT[rt<<1]+IT[rt<<1|1];}

void build(int l,int r,int rt)
{
    IT[rt]=add[rt]=0;
	if(l==r) return;
	int m=(r+l)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
}

inline void pushdown(int rt,int ln,int rn)
{
	if(add[rt])
	{
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		IT[rt<<1]+=add[rt]*ln;
		IT[rt<<1|1]+=add[rt]*rn;
		add[rt]=0;
	}
}

void update(int L,int R,ll C,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		IT[rt]+=C*(r-l+1);
		add[rt]+=C;
		return;
	}
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L<=m) update(L,R,C,l,m,rt<<1);
	if(R>m) update(L,R,C,m+1,r,rt<<1|1);
	pushup(rt);
}

ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return IT[rt];
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	ll ANS=0;
	if(L<=m) ANS+=query(L,R,l,m,rt<<1);
	if(R>m) ANS+=query(L,R,m+1,r,rt<<1|1);
	return ANS;
}

int main()
{
    cin>>rem;
    mlc();
    n=rem.size();
    build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        int c=rem[i-1]-'a';
        update(last[c]+1,i,1,1,n,1);
        last[c]=i;
        ans+=query(i-r[i*2-1]/2+1,i,1,n,1);
    }
    memset(last,0,sizeof(last));
    build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        int c=rem[i-1]-'a';
        update(last[c]+1,i,1,1,n,1);
        last[c]=i;
        ans+=query(i-r[i*2]/2+1,i,1,n,1);
    }
    cout<<ans;
    return 0;
}
