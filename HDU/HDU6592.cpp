#include <bits/stdc++.h>
using namespace std;

int n,bit[400005],from[400005],pre1[400005],pre2[400005],a[400005],tmp[400005],dp1[400005],dp2[400005];

int _find(int x)
{
    return lower_bound(tmp,tmp+n,x)-tmp+1;
}

void modify1(int x,int y,int pos)
{
    for(;x<=n;x+=x&-x)
        if(bit[x]<y) from[x]=pos,bit[x]=y;
}

void modify2(int x,int y,int pos)
{
    for(;x<=n;x+=x&-x)
        if(bit[x]<=y) from[x]=pos,bit[x]=y;
}

int query1(int x,int &pos)
{
    int ret=0;pos=-1;
    for(;x;x-=x&-x)
        if(ret<bit[x]) ret=bit[x],pos=from[x];
    return ret;
}

int query2(int x,int &pos)
{
    int ret=0;pos=-1;
    for(;x;x-=x&-x)
        if(ret<=bit[x]) ret=bit[x],pos=from[x];
    return ret;
}

void print(int now,int tp)
{
    if(now==-1) return;
    if(tp==1)
    {
        printf(" %d",now+1);
        print(pre1[now],tp);
    }
    else
    {
        print(pre2[now],tp);
        if(pre2[now]!=-1) printf(" ");
        printf("%d",now+1);
    }
}

void solve()
{
    for(int i=0;i<n;i++)
        scanf("%d",a+i),tmp[i]=a[i];
    sort(tmp,tmp+n);
    for(int i=0;i<n;i++) a[i]=_find(a[i]);

    for(int i=0;i<=n;i++) from[i]=-1,bit[i]=0;
    for(int i=n-1;i>=0;i--)
    {
        dp1[i]=query2(a[i]-1,pre1[i])+1;
        modify2(a[i],dp1[i],i);
    }
    for(int i=0;i<=n;i++) from[i]=-1,bit[i]=0;
    for(int i=0;i<n;i++)
    {
        dp2[i]=query1(a[i]-1,pre2[i])+1;
        modify1(a[i],dp2[i],i);
    }
    int pos=0;
    for(int i=0;i<n;i++)
        if(dp1[pos]+dp2[pos]<dp1[i]+dp2[i]) pos=i;
    print(pos,2);
    print(pre1[pos],1);
    printf("\n");

    for(int i=0;i<=n;i++) from[i]=-1,bit[i]=0;
    for(int i=n-1;i>=0;i--)
    {
        dp1[i]=query1(a[i]-1,pre1[i])+1;
        modify1(a[i],dp1[i],i);
    }
    for(int i=0;i<=n;i++) from[i]=-1,bit[i]=0;
    for(int i=0;i<n;i++)
    {
        dp2[i]=query2(a[i]-1,pre2[i])+1;
        modify2(a[i],dp2[i],i);
    }
    pos=0;
    for(int i=0;i<n;i++)
        if(dp1[pos]+dp2[pos]<=dp1[i]+dp2[i]) pos=i;
    print(pos,2);
    print(pre1[pos],1);
    printf("\n");
}

int main()
{
    while(~scanf("%d",&n)) solve();
    return 0;
}
