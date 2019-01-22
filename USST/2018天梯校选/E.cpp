#include <cstdio>
#include <algorithm>

int n,le,ans;
struct node
{
    int s,e;
}q[1005];

inline bool cmp(node a,node b){return a.e<b.e;}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&q[i].s,&q[i].e);
        std::sort(q,q+n,cmp);
        le=-1,ans=0;
        for(int i=0;i<n;i++)
            if(le<q[i].s) le=q[i].e,ans++;
        printf("%d\n",ans);
    }
    return 0;
}