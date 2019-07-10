#include <algorithm>
#include <cstdio>
using namespace std;

int fa[27],n,sum,tot;
struct edge
{
    int x,y,val;
}e[205];

bool cmp(edge a,edge b){return a.val<b.val;}
int _find(int x){return x==fa[x]?x:fa[x]=_find(fa[x]);}
void _union(int x,int y){fa[_find(x)]=_find(y);}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        sum=tot=0;
        for(int i=0;i<n;i++) fa[i]=i;
        for(int i=0;i<n-1;i++)
        {
            int t;
            scanf(" %*c%d",&t);
            for(int j=0;j<t;j++)
            {
                char y;int z;
                scanf(" %c%d",&y,&z);
                e[tot].x=i;
                e[tot].y=y-'A';
                e[tot++].val=z;
            }
        }
        sort(e,e+tot,cmp);
        for(int i=0;i<tot;i++)
        {
            if(_find(e[i].x)!=_find(e[i].y))
            {
                sum+=e[i].val;
                _union(e[i].x,e[i].y);
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
