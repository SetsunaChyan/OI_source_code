#include <cstdio>
#include <algorithm>

struct node
{
    int a,b;
}e[100005];
int n,v;

inline bool cmp(node x,node y){return x.a>y.a;}

int main()
{
    while(~scanf("%d",&v)&&v)
    {
        int ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&e[i].a,&e[i].b);
        std::sort(e,e+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(e[i].b<=v)
            {
                ans+=e[i].a*e[i].b;
                v-=e[i].b;
            }
            else
            {
                ans+=e[i].a*v;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}