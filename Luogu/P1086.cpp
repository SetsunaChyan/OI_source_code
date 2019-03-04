#include <cstdio>
#include <algorithm>
#include <cmath>

struct node
{
    int x,y,num;
}map[400];

bool cmp(node a,node b)
{
    return a.num>b.num;
}

int main()
{
    int m,n,k,x,y,ans;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&map[i*n+j].num);
            map[i*n+j].x=i;
            map[i*n+j].y=j;
        }
    std::sort(map,map+n*m,cmp);
    x=-1;y=map[0].y;ans=0;
    for(int i=0;i<m*n&&k>=abs(map[i].x-x)+abs(map[i].y-y)+2+map[i].x;i++)
    {
        k-=abs(map[i].x-x)+abs(map[i].y-y)+1;
        ans+=map[i].num;
        x=map[i].x;
        y=map[i].y;
    }
    printf("%d\n",ans);
    return 0;
}
