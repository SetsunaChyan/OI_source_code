#include <cstdio>
#include <cmath>

const int prime[11]={1,2,3,5,7,11,13,17,19,23,29};
long long maxn=1,maxd=1;
int n;

void dfs(int p,long long num,int ys,int limit)
{
    if(p==11)
    {
        if(ys>maxd||ys==maxd&&num<maxn)
        {
            maxn=num;
            maxd=ys;
        }
        return ;
    }

    int m=1;
    for(int i=0;i<=limit;i++)
    {
        dfs(p+1,num*m,ys*(i+1),i);
        m*=prime[p];
        if(m*num>n) break;
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1,1,1,log(n)/log(2));
    printf("%lld\n",maxn);
    return 0;
}
