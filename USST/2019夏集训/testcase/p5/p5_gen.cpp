#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];
set<pair<int,int> > s;

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int n,int m)
{
    s.clear();
    printf("%d %d\n",n,m);
    while(m--)
    {
        pair<int,int> p;
        do{p=make_pair(rnd(1,n),rnd(1,n));}while(p.first==p.second||s.find(p)!=s.end());
        s.insert(p);
        printf("%d %d\n",p.first,p.second);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=3;i<=30;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(5,5);
        else if(i<=10) gen(10,10);
        else if(i<=15) gen(10,20);
        else if(i<=20) gen(100,50);
        else if(i<=25) gen(10000,10000);
        else if(i<=30) gen(300000,300000);
        fclose(stdout);
    }
    return 0;
}
