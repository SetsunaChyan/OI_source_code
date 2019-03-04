#include <cstdio>
#include <algorithm>

int n,m,par[40001];
struct edge
{
    int a,b,c;
}e[100000];

int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void u(int a,int b)
{
    a=find(a);
    b=find(b);
    par[a]=b;
}

inline bool cmp(edge a,edge b)
{
    return a.c>b.c;
}

int main()
{
    int flag=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=2*n;i++)
        par[i]=i;
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
    std::sort(e,e+m,cmp);
    for(int i=0;i<m;i++)
    {
        u(e[i].a,e[i].b+n);
        u(e[i].a+n,e[i].b);
        if(find(e[i].a)==find(e[i].b))
        {
            printf("%d\n",e[i].c);
            flag=1;
            break;
        }
    }
    if(flag==0) printf("0\n");
    return 0;
}
