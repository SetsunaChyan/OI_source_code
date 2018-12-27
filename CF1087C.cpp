#include <cstdio>
#include <algorithm>

using namespace std;
struct node
{
    int x,y;
}p[3];
int maxy=0,miny=0x3f3f3f3f;

inline bool cmp(node a,node b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
inline int abs(int x){return x<0?-x:x;}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
    for(int i=0;i<3;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        if(maxy<p[i].y) maxy=p[i].y;
        if(miny>p[i].y) miny=p[i].y;
    }
    sort(p,p+3,cmp);
    int ans=p[2].x-p[0].x+1+maxy-miny;
    printf("%d\n",ans);
    for(int i=p[0].x;i<p[1].x;i++)
        printf("%d %d\n",i,p[0].y);
    for(int i=min(p[0].y,p[1].y);i<=max(p[0].y,p[1].y);i++)
        printf("%d %d\n",p[1].x,i);
    for(int i=p[1].x+1;i<=p[2].x;i++)
        printf("%d %d\n",i,p[2].y);
    if(p[2].y<min(p[0].y,p[1].y))
        for(int i=p[2].y;i<min(p[0].y,p[1].y);i++)
            printf("%d %d\n",p[1].x,i);               
    if(p[2].y>max(p[0].y,p[1].y))
        for(int i=p[2].y;i>max(p[0].y,p[1].y);i--)
            printf("%d %d\n",p[1].x,i);
    return 0;
}