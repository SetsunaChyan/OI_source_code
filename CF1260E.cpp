#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int,vector<int>,greater<int>> q;
int n,me,last,cur,p[1000005];
ll ans;

int main()
{
    scanf("%d",&n);
    last=cur=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",p+i);
        if(p[i]==-1) me=i;
    }
    for(int last=n>>1;last;last>>=1)
    {
        if(cur==me) break;
        q.push(p[cur--]);
        ans+=q.top();q.pop();
        for(int i=1;i<last&&cur>me;cur--,i++) q.push(p[cur]);
    }
    printf("%lld",ans);
    return 0;
}
