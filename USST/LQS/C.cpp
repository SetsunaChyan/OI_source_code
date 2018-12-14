#include <cstdio>
#include <algorithm>

struct node
{
    int pos,v;
}e[1001];

inline bool cmp(node a,node b){return a.v<b.v;}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&e[i].v);
        e[i].pos=i+1;
    }
    std::sort(e,e+n,cmp);
    printf("%d",e[0].pos);
    for(int i=1;i<n;i++)
        printf(" %d",e[i].pos);
    return 0;
}