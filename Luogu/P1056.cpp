#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int num,times;
    node(){times=0;}
};

int m,n,k,l,d;
node c[1000],r[1000];

int min(const int a,const int b)
{
    return a<b?a:b;
}

bool cmp1(const node a,const node b)
{
    return a.times>b.times;
}

bool cmp2(const node a,const node b)
{
    return a.num<b.num;
}

int main()
{
    int i;
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(i=0;i<d;i++)
    {
        int x1,y1,x2,y2,temp;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(y1==y2)
        {
            temp=min(x1,x2);
            r[temp].times++;
            r[temp].num=temp;
        }
        else
        {
            temp=min(y1,y2);
            c[temp].times++;
            c[temp].num=temp;
        }
    }
    sort(r,r+m,cmp1);
    sort(c,c+n,cmp1);
    sort(r,r+k,cmp2);
    sort(c,c+l,cmp2);
    printf("%d",r[0].num);
    for(i=1;i<k;i++) printf(" %d",r[i].num);
    printf("\n");
    printf("%d",c[0].num);
    for(i=1;i<l;i++) printf(" %d",c[i].num);
    return 0;
}

