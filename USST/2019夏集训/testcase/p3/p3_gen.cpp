#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int mod)
{
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int k=rnd(1,mod);
        if(k==1) printf("M "); else printf("C ");
        printf("%d %d\n",rnd(1,min(30000,n)),rnd(1,min(30000,n)));
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=30;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(10,3);
        else if(i<=10) gen(20,3);
        else if(i<=15) gen(20,4);
        else if(i<=20) gen(50,4);
        else if(i<=25) gen(30000,4);
        else if(i<=30) gen(500000,5);
        fclose(stdout);
    }
    return 0;
}
