#include <cstdio>
#include <algorithm>

int n;
struct node
{
    int a,b;
}p[1000000];

bool cmp(node a,node b)
{
    return a.b<b.b;
}

int main()
{
    int ans=0,k=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].a,&p[i].b);
    std::sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(p[i].a>=k)
        {
            ans++;
            k=p[i].b;
        }
    }
    printf("%d",ans);
    return 0;
}
