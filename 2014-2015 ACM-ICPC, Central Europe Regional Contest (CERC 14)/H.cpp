#include <bits/stdc++.h>
using namespace std;

int x[10]={3,0,0,0,1,1,1,2,2,2},y[10]={1,0,1,2,0,1,2,0,1,2};
vector<int> v,a;

void gao()
{
    for(int i=1;i<=200;i++)
    {
        v.clear();
        int t=i,flag=1;
        while(t)
        {
            v.push_back(t%10);
            t/=10;
        }
        for(int j=0;j<v.size()-1;j++)
            if(x[v[j]]<x[v[j+1]]||y[v[j]]<y[v[j+1]]) flag=0;
        if(flag) a.push_back(i);
    }
    //for(auto p:a) printf("%d ",p);
}

int main()
{
    gao();
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int mx=0x3f3f3f3f,x;
        scanf("%d",&x);
        for(auto p:a)
            if(abs(p-x)<abs(mx-x)) mx=p;
        printf("%d\n",mx);
    }
    return 0;
}
