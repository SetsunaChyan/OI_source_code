#include <bits/stdc++.h>
using namespace std;

int p[105],n,m;
vector<int> ans;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        for(int j=l;j<=r;j++) p[j]=1;
    }
    for(int i=1;i<=m;i++) if(!p[i]) ans.push_back(i);
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d ",p);
    return 0;
}
