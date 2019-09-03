#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int r,c,m,maxn,tot;
int p[250][250],s[250][250][1050],num[250][250][1050];
int root[500050];
struct node
{
    int l,r,sum,size;
}tree[500050<<5];
int sum(int a1,int b1,int a2,int b2,int k)
{
    return s[a2][b2][k]-s[a1-1][b2][k]-s[a2][b1-1][k]+s[a1-1][b1-1][k];
}
int numm(int a1,int b1,int a2,int b2,int k)
{
    return num[a2][b2][k]-num[a1-1][b2][k]-num[a2][b1-1][k]+num[a1-1][b1-1][k];
}
int update(int u,int l,int r,int k)
{
    int rt=++tot;
    tree[rt]=tree[u];
    tree[rt].sum=tree[u].sum+k;
    tree[rt].size=tree[u].size+1;
    if(l==r)return rt;
    int mid=(l+r)>>1;
    if(k<=mid)tree[rt].l=update(tree[u].l,l,mid,k);
    else tree[rt].r=update(tree[u].r,mid+1,r,k);
    return rt;
}
int query(int u,int v,int l,int r,int k)
{
    int ans=0;
    while(l<r)
    {
        int mid=(l+r)>>1;
        int x=tree[tree[v].r].sum-tree[tree[u].r].sum;
        if(x<k)ans+=tree[tree[v].r].size-tree[tree[u].r].size,k-=x,r=mid,v=tree[v].l,u=tree[u].l;
        else l=mid+1,u=tree[u].r,v=tree[v].r;
    }
    ans+=(k+l-1)/l;
    return ans;
}
int main()
{
    scanf("%d%d%d",&r,&c,&m);
    if(r!=1)
    {
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                scanf("%d",&p[i][j]);
                maxn=max(maxn,p[i][j]);
            }
        for(int k=0;k<=maxn;k++)
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                {
                    s[i][j][k]=s[i-1][j][k]+s[i][j-1][k]-s[i-1][j-1][k]+(p[i][j]>=k?p[i][j]:0);
                    num[i][j][k]=num[i-1][j][k]+num[i][j-1][k]-num[i-1][j-1][k]+(p[i][j]>=k?1:0);
                }
        for(int i=1;i<=m;i++)
        {
            int x1,y1,x2,y2,h;
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
            if(sum(x1,y1,x2,y2,0)<h){printf("-1\n");continue;}
            int l=0,r=maxn,ans=-1;
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(sum(x1,y1,x2,y2,mid)>=h)ans=mid,l=mid;
                else r=mid-1;
            }
            if(ans==-1){printf("-1\n");continue;}
            else    printf("%d\n",numm(x1,y1,x2,y2,ans)-(sum(x1,y1,x2,y2,ans)-h)/ans);
        }
    }
    else
    {
        int x;
        for(int i=1;i<=c;i++)scanf("%d",&x),root[i]=update(root[i-1],1,1000,x);
        for(int i=1;i<=m;i++)
        {
            int a,b,c,d,h;
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&h);
            if(tree[root[d]].sum-tree[root[b-1]].sum<h){printf("-1\n");continue;}
            else printf("%d\n",query(root[b-1],root[d],1,1000,h));
        }
    }
    return 0;
}
