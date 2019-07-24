#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];
int dis[500005];
set<int> s;

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int d,int dlimit,int limit)
{
    s.clear();
    printf("%d %d %d\n",n,d,rnd(1,n/2)*limit/2);
    dis[0]=0;
    for(int i=1;i<=n;i++)
        dis[i]=dis[i-1]+rnd(1,dlimit);
    //sort(dis,dis+n);
    for(int i=1;i<=n;i++)
    {
        int k=rnd(0,limit);
        if(rand()&1) k*=-1;
        printf("%d %d\n",dis[i],k);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=3;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(10,1,20,10);
        else if(i<=15) gen(100,1,20,100);
        else if(i<=20) gen(500000,1,100,100000);
        fclose(stdout);
    }
    return 0;
}
