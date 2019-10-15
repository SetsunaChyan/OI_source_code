#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct Q
{
    int l,r,pos;
}q[100005];
int n,m,bit[100005],ans[100005],a[100005],r[100005];
vector<pii> p;

bool cmp(Q x,Q y)
{
    return x.l>y.l;
}

void add(int x,int y)
{
    for(;x<=n;x+=x&-x) bit[x]+=y;
}

int sum(int x)
{
    int ret=0;
    for(;x;x-=x&-x) ret+=bit[x];
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),r[a[i]]=i;
    for(int i=0;i<m;i++)
        scanf("%d%d",&q[i].l,&q[i].r),q[i].pos=i;
    sort(q,q+m,cmp);
    for(int i=1;i<=n;i++)
        for(int j=a[i]<<1;j<=n;j+=a[i])
            p.emplace_back(min(i,r[j]),max(i,r[j]));
    sort(p.begin(),p.end());
    for(int i=0,j=p.size()-1;i<m;i++)
    {
        while(j>=0&&p[j].first>=q[i].l)
        {
            add(p[j].second,1);
            j--;
        }
        ans[q[i].pos]=sum(q[i].r);
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
