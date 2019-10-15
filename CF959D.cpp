#include <bits/stdc++.h>
using namespace std;

int n,vis[2000005],limit=1;
set<int> used,have;
vector<int> ans,prime;
queue<int> q;

void seive()
{
    int n=2000000;
    for(int i=2;i<=n;i++)
        if(!vis[i])
        {
            have.insert(i);
            prime.push_back(i);
            for(long long j=(long long)i*i;j<=n;j+=i) vis[j]=1;
        }
}

int main()
{
    seive();
    scanf("%d",&n);
    while(n--)
    {
        int x,flag=1;
        scanf("%d",&x);
        if(!limit)
        {
            ans.push_back(q.front());
            q.pop();
            continue;
        }
        for(auto p:used)
        {
            if(p*p>x) break;
            if(x%p==0)
            {
                flag=0;
                break;
            }
        }
        if(used.find(x)!=used.end()) flag=0;
        if(flag)
        {
            ans.push_back(x);
            for(auto p:prime)
            {
                if(p*p>x) break;
                if(x%p==0)
                {
                    have.erase(p),used.insert(p);
                    while(x%p==0) x/=p;
                }
            }
            if(x>1) have.erase(x),used.insert(x);
            continue;
        }
        limit=0;
        auto it=have.upper_bound(x);
        ans.push_back(*it);
        used.insert(*it);
        have.erase(it);
        for(auto p:have) q.push(p);
    }
    for(auto p:ans) printf("%d ",p);
    return 0;
}
