#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans,n,m,a[200005];
ll sum;

int solve()
{
    scanf("%d%d",&n,&m);
    ans=sum=0;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    priority_queue<int> q;
    priority_queue<int,vector<int>,greater<int> > q2;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        while(sum>m)
        {
            ans++;
            sum-=q.top();
            q2.push(q.top());
            q.pop();
        }
        q.push(a[i]);
        printf("%d ",ans);
        while(!q2.empty()&&q.top()>q2.top())
        {
            ll k=q2.top();
            sum+=k;
            sum-=q.top();
            q2.pop();
            q2.push(q.top());
            q.pop();
            q.push(k);
        }
        while(!q2.empty()&&sum+q2.top()<=m)
        {
            sum+=q2.top();
            ans--;
            q.push(q2.top());
            q2.pop();
        }
    }
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
