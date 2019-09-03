#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int inf=0x3f3f3f3f;
int n,q,a[100005],b[100005];
int M,tree[MAXN<<2];
inline int read()
{
   register int s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9') ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s;
}
inline void write(int x)
{
    register int tot=0;
    static int wt[20];
    if(x==0)
    {
        puts("0");
        return;
    }
    while(x) wt[tot++]=x%10,x/=10;
    for(register int i=tot-1;i>=0;i--)
        putchar(wt[i]+'0');
    puts("");
}
void up(int i)
{
	tree[i]=max(tree[i<<1],tree[i<<1|1]);
}
inline void update(int x,int v)
{
	for(tree[x+=M]=v,x>>=1;x;x>>=1) up(x);
}
void build()
{
	for(M=1;M<n;M<<=1);
	for(int i=M+1;i<=M+n;i++) tree[i]=a[i-M];
    for(int i=M;i>=1;i--) up(i);
}
int query(int l,int r)//求[l~r]的最大值
{
	int ans=0;
	//l^r^1判断是否是兄弟节点，>0时是兄弟节点
	//是兄弟是退出循环
	for(l=l+M-1,r=r+M+1; l^r^1; l>>=1,r>>=1)
	{
		//l&1^1,r&1分别判断偶数和奇数
		if(l&1^1) ans=max(ans,tree[l^1]);//l+1
		if(r&1)   ans=max(ans,tree[r^1]);//r-1
	}
	return ans;
}
int get(int l,int r,int lim)
{
    if(l==r)
    {
        if(a[l]<=lim)
            return n+1;
        else
            return l;
    }
    int m=l+r>>1,ll=-1,rr=-1;
    if(l<=m)ll=query(l,m);
    if(m<r)rr=query(m+1,r);
    if(ll>lim)
        return get(l,m,lim);
    if(rr>lim)
        return get(m+1,r,lim);
    return n+1;
}

int main()
{
//    freopen("22.in","r",stdin);
//    freopen("22.out","w",stdout);
    int _=read(),p,k,r;
    while(_--)
    {
        n=read(),q=read();
        for(int i=1;i<=n;i++) b[i]=read(),a[b[i]]=i;
        build();
        int ans=0;
        while(q--)
        {
            if(read()==1)
                p=read(),
                p^=ans,
                update(b[p],inf),a[b[p]]=inf;
            else
                r=read(),k=read(),
                r^=ans,k^=ans,
                write(ans=get(k,n,r));
        }
    }
    return 0;
}
/*
int main()
{
//    freopen("22.in","r",stdin);
//    freopen("22.out","w",stdout);
    int _=read(),p,k,r,LL,RR,mid;
    while(_--)
    {
        n=read(),q=read();
        n++;a[n]=inf;
        for(int i=1;i<=n;i++)
            b[i]=read(),a[b[i]]=i;
        build();
        int ans=0;
        while(q--)
        {
            if(read()==1)
                p=read(),
                p^=ans,
                update(b[p],inf),a[b[p]]=inf;
            else
            {
                r=read(),k=read(),
                r^=ans,k^=ans,
                LL=k,RR=n;
                while(LL<RR)
                {
                    mid=LL+RR>>1;
                    if(query(LL,mid)>r) RR=mid; else LL=mid+1;
                }
                write(ans=LL);
            }
        }
    }
    return 0;
}
*/
