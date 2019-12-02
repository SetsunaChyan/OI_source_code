#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];
int fa[100005];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

int _find(int x){return fa[x]==x?x:fa[x]=_find(fa[x]);}

void gen(int n)
{
    printf("%d\n",n);
    for(int i=0;i<n;i++) printf("%d ",rnd(1,n));
    printf("\n");
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<n;i++)
    {
        int x,y;
        while(1)
        {
            x=rnd(1,n);y=rnd(1,n);
            if(_find(x)==_find(y)) continue;
            fa[_find(y)]=x;
            break;
        }
        printf("%d %d\n",x,y);
    }
}

void gen_l()
{
    int n=100000;
    printf("%d\n",n);
    for(int i=0;i<n;i++) printf("%d ",rnd(1,n));
    printf("\n");
    for(int i=1;i<n;i++)
        printf("%d %d\n",i,i+1);
}

int main()
{
    srand(time(NULL));
    for(int i=3;i<=21;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(10);
        else if(i<=20) gen(100000);
        else gen_l();
        fclose(stdout);
    }
    return 0;
}
