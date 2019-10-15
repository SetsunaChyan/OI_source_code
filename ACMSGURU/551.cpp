#include <bits/stdc++.h>
using namespace std;

int n,t1,t2,flg1,flg2,ans,tt;
vector<int> t;

int main()
{
    scanf("%d%d%d",&n,&t1,&t2);
    for(int i=1;i<=n;i++) t.push_back(t1*i),t.push_back(t2*i);
    sort(t.begin(),t.end());
    unique(t.begin(),t.end());
    for(auto now:t)
    {
        if(!flg1&&now%t1==0) ans++;
        if(!flg2&&now%t2==0) ans++;
        if(now%t1==0&&ans>=n) flg1=1;
        if(now%t2==0&&ans>=n) flg2=1;
        if(flg1&&flg2)
        {
            tt=now;
            break;
        }
    }
    printf("%d %d",ans,tt);
    return 0;
}
