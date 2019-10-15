#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int wt[20],n,m;
int T[2000005];
int ans[500005],a[500005];
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
}
void build(int l=1,int r=n,int rt=1)
{
    if(l==r)
    {
        a[l]=T[rt]=read();
        return;
    }
    int m=l+r>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    T[rt]=max(T[rt<<1],T[rt<<1|1]);
}
int query(int l,int r,int val,int L=1,int R=n,int rt=1)
{
    if(L==R) return L;
    int m=L+R>>1;
    if(m<r&&T[rt<<1|1]>=val)
        return query(l,r,val,m+1,R,rt<<1|1);
    if(l<=m)
        return query(l,r,val,L,m,rt<<1);
    return -1;
}
int main()
{
	n=read(),m=read();build();
	for(int i=1;i<=n;i++)
	{
		int l=i+1,r=n,v=a[i]+m;
        int k=query(l,r,v);
        if(k!=-1) k-=i+1;
        ans[i]=k;
	}
	for(int i=1;i<=n;i++)
        printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
