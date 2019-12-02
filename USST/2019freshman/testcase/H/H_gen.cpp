#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];
int fa[3005];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

int _find(int x){return fa[x]==x?x:fa[x]=_find(fa[x]);}

void gen(int upper)
{
    int n=rnd(3,upper);
    int k=rnd(1,n);
    printf("%d %d\n",n,k);
    for(int i=0;i<n;i++) fa[i]=i;
    for(int i=1;i<n;i++)
    {
        int x;
        while(1)
        {
            x=rnd(0,n-1);
            if(_find(x)==_find(i)) continue;
            fa[_find(i)]=x;
            break;
        }
        printf("%d\n",x);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=3;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(10);
        else gen(2500);
        fclose(stdout);
    }
    return 0;
}
