#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<vector<int>,int>h;
vector<int> gao(ll k)
{
    vector<int>v;
    for(int i=2;k;i++)
        v.push_back(k%i),k/=i;
    sort(begin(v),end(v));
    return v;
}
int main()
{
    int _=1;
    //scanf("%d",&_);
    for(ll i=1;i<=1e5;i++)
        h[gao(i)]++;
    for(auto p:h)
    if(p.first.size()==5){
            for(auto v:p.first)
                printf("%d ",v);printf("%d\n",p.second);}
    while(_--)
    {
        for(int k=1;k<=1000;k++)
        {
            //h.clear();
        //scanf("%lld",&k);
            //for(ll i=1;i<=k*5;i++)
            //    h[gao(i)]++;
            printf("%4d:%d\n",k,h[gao(k)]);
        }
    }
    return 0;
}
