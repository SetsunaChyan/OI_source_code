#include <bits/stdc++.h>
using namespace std;

/*
    空间 O(nlogn)
    单点修改,区间rank,前驱后继(不存在则为±2147483647) 单次 O(log^2(n))
    区间排名为k的值 单次 O(log^3(n))
*/

const int inf=2147483647;
const int MAXN=50005;
int root[MAXN<<2],n,m,a[MAXN];
struct Treap
{
    int tot;
    struct node
    {
        int lc,rc,dat,val,cnt,siz;
    }bst[MAXN*4*20];

    int newnode(int v)
    {
        bst[++tot].val=v;
        bst[tot].dat=rand();
        bst[tot].siz=bst[tot].cnt=1;
        bst[tot].lc=bst[tot].rc=0;
        return tot;
    }

    void zig(int &rt)
    {
        int p=bst[rt].lc;
        bst[rt].lc=bst[p].rc;
        bst[p].rc=rt;
        rt=p;
        pushup(bst[rt].rc);
        pushup(rt);
    }

    void zag(int &rt)
    {
        int p=bst[rt].rc;
        bst[rt].rc=bst[p].lc;
        bst[p].lc=rt;
        rt=p;
        pushup(bst[rt].lc);
        pushup(rt);
    }

    void pushup(int rt)
    {
        bst[rt].siz=bst[rt].cnt;
        if(bst[rt].lc) bst[rt].siz+=bst[bst[rt].lc].siz;
        if(bst[rt].rc) bst[rt].siz+=bst[bst[rt].rc].siz;
    }

    int build()
    {
        int rt=newnode(-inf);
        bst[rt].rc=newnode(inf);
        pushup(rt);
        return rt;
    }

    void _delete(int &rt,int x)
    {
        if(bst[rt].val==x)
        {
            if(bst[rt].cnt>1)
            {
                bst[rt].cnt--;
                pushup(rt);
                return;
            }
            if(bst[rt].lc||bst[rt].rc)
            {
                if(bst[rt].rc==0||bst[bst[rt].rc].dat<bst[bst[rt].lc].dat)
                    zig(rt),_delete(bst[rt].rc,x);
                else
                    zag(rt),_delete(bst[rt].lc,x);
                pushup(rt);
            }
            else rt=0;
            return;
        }
        if(x<bst[rt].val) _delete(bst[rt].lc,x);
        else _delete(bst[rt].rc,x);
        pushup(rt);
    }

    void _insert(int &rt,int x)
    {
        if(rt==0)
        {
            rt=newnode(x);
            return;
        }
        if(bst[rt].val==x) bst[rt].cnt++;
        else if(x<bst[rt].val)
        {
            _insert(bst[rt].lc,x);
            if(bst[bst[rt].lc].dat>bst[rt].dat) zig(rt);
        }
        else
        {
            _insert(bst[rt].rc,x);
            if(bst[bst[rt].rc].dat>bst[rt].dat) zag(rt);
        }
        pushup(rt);
    }

    int get_rank(int rt,int x)
    {
        if(!rt) return 1;
        if(bst[rt].val==x) return bst[bst[rt].lc].siz+1;
        if(x<bst[rt].val) return get_rank(bst[rt].lc,x);
        else return get_rank(bst[rt].rc,x)+bst[bst[rt].lc].siz+bst[rt].cnt;
    }

    int get_num(int rt,int x)
    {
        if(!rt) return 0;
        if(bst[rt].val==x) return bst[bst[rt].lc].siz+bst[rt].cnt;
        if(x<bst[rt].val) return get_num(bst[rt].lc,x);
        else return get_num(bst[rt].rc,x)+bst[bst[rt].lc].siz+bst[rt].cnt;
    }

    int get_prev(int rt,int x)
    {
        int ret=-inf;
        while(rt)
        {
            if(bst[rt].val==x)
            {
                if(bst[rt].lc)
                {
                    rt=bst[rt].lc;
                    while(bst[rt].rc) rt=bst[rt].rc;
                    ret=bst[rt].val;
                }
                break;
            }
            if(bst[rt].val<x&&bst[rt].val>ret) ret=bst[rt].val;
            if(x<bst[rt].val) rt=bst[rt].lc;
            else rt=bst[rt].rc;
        }
        return ret;
    }

    int get_nxt(int rt,int x)
    {
        int ret=inf;
        while(rt)
        {
            if(bst[rt].val==x)
            {
                if(bst[rt].rc)
                {
                    rt=bst[rt].rc;
                    while(bst[rt].lc) rt=bst[rt].lc;
                    ret=bst[rt].val;
                }
                break;
            }
            if(bst[rt].val>x&&bst[rt].val<ret) ret=bst[rt].val;
            if(x<bst[rt].val) rt=bst[rt].lc;
            else rt=bst[rt].rc;
        }
        return ret;
    }
}treap;

void build(int rt,int l,int r)
{
    root[rt]=treap.build();
    if(l==r) return;
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void modify(int rt,int l,int r,int x,int v,int y)
{
    if(y==-1) treap._delete(root[rt],v);
    else treap._insert(root[rt],v);
    if(l==r) return;
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,v,y);
    else modify(rt<<1|1,m+1,r,x,v,y);
}

int query(int rt,int l,int r,int op,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        if(op==1) return treap.get_rank(root[rt],x)-2;
        if(op==2) return treap.get_num(root[rt],x)-1;
        if(op==4) return treap.get_prev(root[rt],x);
        if(op==5) return treap.get_nxt(root[rt],x);
    }
    int m=l+r>>1,ret;
    if(op==1||op==2)
    {
        ret=0;
        if(L<=m) ret+=query(rt<<1,l,m,op,L,R,x);
        if(m<R) ret+=query(rt<<1|1,m+1,r,op,L,R,x);
    }
    if(op==4)
    {
        ret=-inf;
        if(L<=m) ret=max(ret,query(rt<<1,l,m,op,L,R,x));
        if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,op,L,R,x));
    }
    if(op==5)
    {
        ret=inf;
        if(L<=m) ret=min(ret,query(rt<<1,l,m,op,L,R,x));
        if(m<R) ret=min(ret,query(rt<<1|1,m+1,r,op,L,R,x));
    }
    return ret;
}

int main()
{
    srand(time(0));
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        modify(1,1,n,i,a[i],1);
    }
    while(m--)
    {
        int op,l,r,k,pos;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",query(1,1,n,op,l,r,k)+1);
        }
        else if(op==2)
        {
            scanf("%d%d%d",&l,&r,&k);
            int L=-inf,R=inf,mid;
            while(L<R)
            {
                mid=(L+R+1)>>1;
                if(query(1,1,n,1,l,r,mid)+1>k) R=mid-1; else L=mid;
            }
            printf("%d\n",L);
        }
        else if(op==3)
        {
            scanf("%d%d",&pos,&k);
            modify(1,1,n,pos,a[pos],-1);
            a[pos]=k;
            modify(1,1,n,pos,k,1);
        }
        else
        {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",query(1,1,n,op,l,r,k));
        }
    }
    return 0;
}
