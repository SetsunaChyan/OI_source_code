#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int m,int limit,int mod)
{
    int now=1;
    printf("%d %d\n",m,mod);
    printf("A 0\n");
    for(int i=1;i<m;i++)
    {
        int op=rand()&1;
        if(op==1)
        {
            int x=rnd(1,now);
            printf("Q %d\n",x);
        }
        else
        {
            int n=rnd(0,limit);
            //if(rand()&1) n*=-1;
            printf("A %d\n",n);
            now++;
        }
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=25;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen(20,100,100);
        else if(i<=15) gen(1000,1000,1000);
        else if(i<=25) gen(200000,1000000000,998244353);
        fclose(stdout);
    }
    return 0;
}
