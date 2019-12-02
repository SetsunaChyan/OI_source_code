#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x;
int cnt[25];
vector<int> a;

void solve(ll x)
{
    a.clear();
    int cur=2;
    while(x)
    {
        a.push_back(x%cur);
        x/=cur;
        cur++;
    }
    if(a.size()==4)
    {
        for(auto p:a) printf("%d ",p);
        printf("\n");
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=1000000;i++) solve(i);
    return 0;
}
