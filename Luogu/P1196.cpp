#include <cstdio>

int n;

struct node
{
    int par,rank,num,tail;
}bcj[30001];

inline int abs(int x)
{
    if(x<0) return -x; else return x;
}

inline int find(int x,int &u)
{
    if(bcj[x].par==x)
    {
        u=0;
        return x;
    }
    else
    {
        bcj[x].par=find(bcj[x].par,u);
        u+=bcj[x].num;
        bcj[x].num=u;
        return bcj[x].par;
    }
}

inline void un(int a,int b)
{
    int t;
    int x=find(a,t);
    int y=find(b,t);
    if(bcj[x].rank<bcj[y].rank)
    {
        t=x;
        x=y;
        x=t;
    }
    if(x!=y)
    {
        if(bcj[x].rank==bcj[y].rank)
        {
            bcj[y].par=bcj[x].tail;
            bcj[x].rank++;
        }
        else
            bcj[y].par=bcj[x].tail;
    }
    bcj[x].tail=bcj[y].tail;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=30000;i++)
    {
        bcj[i].par=i;
        bcj[i].tail=i;
        bcj[i].num=1;
        bcj[i].rank=0;
    }
    while(n--)
    {
        int a,b,ca,cb;
        char c;
        scanf(" %c%d%d",&c,&a,&b);
        if(c=='C')
        {
            if(find(a,ca)==find(b,cb))
                printf("%d\n",abs(ca-cb)-1);
            else
                printf("-1\n");
        }
        else
        {
            un(a,b);
        }
    }
    return 0;
}
