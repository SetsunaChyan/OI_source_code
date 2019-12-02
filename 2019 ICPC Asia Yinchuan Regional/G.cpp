#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int n,seg[4][MAXN<<2],lazy[4][MAXN<<2];

inline void pushdown(int ROOT,int rt)
{
    if(!lazy[ROOT][rt]) return;
    int &x=lazy[ROOT][rt];
    lazy[ROOT][rt<<1]+=x,lazy[ROOT][rt<<1|1]+=x;
    seg[ROOT][rt<<1]+=x,seg[ROOT][rt<<1|1]+=x;
    x=0;
}

void modify(int ROOT,int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        seg[ROOT][rt]+=x;
        lazy[ROOT][rt]+=x;
        return;
    }
    pushdown(ROOT,rt);
    int m=l+r>>1;
    if(L<=m) modify(ROOT,rt<<1,l,m,L,R,x);
    if(m<R) modify(ROOT,rt<<1|1,m+1,r,L,R,x);
    seg[ROOT][rt]=max(seg[ROOT][rt<<1],seg[ROOT][rt<<1|1]);
}

int query(int ROOT,int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[ROOT][rt];
    pushdown(ROOT,rt);
    int ret=0,m=l+r>>1;
    if(L<=m) ret=max(ret,query(ROOT,rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query(ROOT,rt<<1|1,m+1,r,L,R));
    seg[ROOT][rt]=max(seg[ROOT][rt<<1],seg[ROOT][rt<<1|1]);
    return ret;
}
int q,to[11];
vector<int>v[11];
int main()
{
    v[2]=vector<int>{2};
    v[3]=vector<int>{3};
    v[4]=vector<int>{2,2};
    v[5]=vector<int>{5};
    v[6]=vector<int>{2,3};
    v[7]=vector<int>{7};
    v[8]=vector<int>{2,2,2};
    v[9]=vector<int>{3,3};
    v[10]=vector<int>{2,5};
    to[2]=0;
    to[3]=1;
    to[5]=2;
    to[7]=3;
    scanf("%d%d",&n,&q);
    while(q--)
    {
        char op[22];
        int l,r,x;
        scanf("%s%d%d",op,&l,&r);
        if(op[1]=='U')
        {
            scanf("%d",&x);
            for(auto vv:v[x])
                modify(to[vv],1,1,n,l,r,1);
        }
        else
        {
            int ans=0;
            for(int i=0;i<4;i++)
            {
                int t=query(i,1,1,n,l,r);
                if(ans<t)
                    ans=t;
            }
            printf("ANSWER %d\n",ans);
        }
    }
    return 0;
}
