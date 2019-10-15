#include <bits/stdc++.h>
using namespace std;

int n,x,m[55][55];
vector<int> ans;

int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
            scanf("%d",&y),m[i][y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(m[i][x]||i==x) continue;
        int flag=0;
        for(int j=1;j<=n;j++) if(j!=x&&m[i][j]&&m[j][x]) flag++;
        if(flag) ans.push_back(i);
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d ",p);
    return 0;
}
