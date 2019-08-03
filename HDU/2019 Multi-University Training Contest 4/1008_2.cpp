#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
typedef long long int ll;
int n,q;
vector<int>T[MAXN<<2];
void build(int l=1,int r=n,int rt=1)
{
    T[rt].clear();
    if(l==r)
    {
        int t;
        scanf("%d",&t);
        T[rt].push_back(t);
        return;
    }
    int m=l+r>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    int pl=0,pr=0;
    while(pl<T[rt<<1].size()&&pr<T[rt<<1|1].size())
    {
        if(T[rt<<1][pl]<T[rt<<1|1][pr])
            T[rt].push_back(T[rt<<1][pl]),++pl;
        else
            T[rt].push_back(T[rt<<1|1][pr]),++pr;
    }
    while(pl<T[rt<<1].size())
        T[rt].push_back(T[rt<<1][pl]),++pl;
    while(pr<T[rt<<1|1].size())
        T[rt].push_back(T[rt<<1|1][pr]),++pr;
}
int query(int l,int r,int lb,int rb,int L=1,int R=n,int rt=1)
{
    if(l<=L&&R<=r)
        return upper_bound(T[rt].begin(),T[rt].end(),rb)-lower_bound(T[rt].begin(),T[rt].end(),lb);
    int res=0;
    int m=L+R>>1;
    if(l<=m)
        res+=query(l,r,lb,rb,L,m,rt<<1);
    if(m<r)
        res+=query(l,r,lb,rb,m+1,R,rt<<1|1);
    return res;
}
int main()
{
    //freopen("1008t.in","r",stdin);
    //freopen("1008t2.out","w",stdout);
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&q);
        build();
        int ans=0;
        while(q--)
        {
            int l,r,p,k;
            scanf("%d%d%d%d",&l,&r,&p,&k);
            l^=ans,r^=ans,p^=ans,k^=ans;
            int ll=0,rr=1e6,m;
            while(ll<rr)
            {
                m=ll+rr>>1;
                if(query(l,r,p-m,p+m)<k)
                    ll=m+1;
                else
                    rr=m;
            }
            printf("%d\n",ans=ll);
        }
    }
    return 0;
}
