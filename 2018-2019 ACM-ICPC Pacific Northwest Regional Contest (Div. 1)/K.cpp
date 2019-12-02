#include <bits/stdc++.h>
using namespace std;
int p[]={0,0,1,2,3,4,5,6,5,4,3,2,1};
pair<double,double> solve(vector<int>v)
{
    if(v.empty())return {0,0};
    int n=v.size(),num=0;
    for(auto x:v)
        num=num*10+x;
    double mi=0,ma=0;
    for(int k=2;k<=12;k++)
    {
        bool f=0;
        double l=2e9,r=-2e9;
        for(int i=0;i<(1<<n);i++)
        {
            int s=0;
            for(int j=0;j<n;j++)
                if((i>>j)&1)
                    s+=v[j];
            if(s==k)
            {
                f=1;
                vector<int>t;
                for(int j=0;j<n;j++)
                    if(~(i>>j)&1)
                        t.push_back(v[j]);
                auto p=solve(t);
                l=min(l,p.first);
                r=max(r,p.second);
            }
        }
        if(f)
            mi+=p[k]/36.0*l,ma+=p[k]/36.0*r;
        else
            mi+=p[k]/36.0*num,ma+=p[k]/36.0*num;
    }
    //for(auto x:v)
    //    printf("%d",x);
    //printf("\n%f %f\n",mi,ma);
    return {mi,ma};
}
int main()
{
    vector<int>v;
    int x=3,y=1,t=12349;
    scanf("%d%d%d",&t,&x,&y);
    int n,a1=-1,b1=-1;
    double a2=t,b2=t;
    while(t)
        v.push_back(t%10),t/=10;
    reverse(v.begin(),v.end());
    n=v.size();
    for(int i=0;i<(1<<n);i++)
    {
        int s=0;
        for(int j=0;j<n;j++)
            if((i>>j)&1)
                s+=v[j];
        if(s==x+y)
        {
            vector<int>t;
            for(int j=0;j<n;j++)
                if(~(i>>j)&1)
                    t.push_back(v[j]);
            auto p=solve(t);
            if(p.first<a2||a1==-1)
            {
                a2=p.first;
                int t=0;
                for(int j=0;j<n;j++)
                    if((i>>j)&1)
                       t=t*10+v[j];
                a1=t;
            }
            if(p.second>b2||b1==-1)
            {
                b2=p.second;
                int t=0;
                for(int j=0;j<n;j++)
                    if((i>>j)&1)
                       t=t*10+v[j];
                b1=t;
            }
        }
    }
    printf("%d %.5f\n%d %.5f\n",a1,a2,b1,b2);
    return 0;
}
