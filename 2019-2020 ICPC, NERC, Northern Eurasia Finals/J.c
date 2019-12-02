#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int,int>h;
void ok(int s)
{
    int k,b;
    for(auto p:h)
    {
        k=p.second/s;
        b=p.second%s;
        if(k<b)return;
        ans+=k;
    }
    printf("%d\n",ans);
}
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
