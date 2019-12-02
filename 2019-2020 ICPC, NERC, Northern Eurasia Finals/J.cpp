#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int,int>h;
bool ok(int s)
{
    int k,b,ans=0;
    for(auto p:h)
    {
        k=p.second/s+(p.second%s!=0);
        b=k*s-p.second;
        if(k<b)return false;
        ans+=k;
    }
    printf("%d\n",ans);
    return true;
}
/*
3
11
1 5 1 5 1 5 1 1 1 1 5
6
1 2 2 2 2 1
5
4 3 3 1 2
*/
int main()
{
    int _;scanf("%d",&_);while(_--)
    {
        h.clear();
        scanf("%d",&n);
        for(int t,i=1;i<=n;i++)
            scanf("%d",&t),h[t]++;
        int mi=1e9;
        for(auto p:h)
            mi=min(mi,p.second);
        for(int s=mi+1;s>=1;s--)
            if(ok(s))
                break;
    }
    return 0;
}
