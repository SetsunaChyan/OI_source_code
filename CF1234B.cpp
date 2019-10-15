#include <bits/stdc++.h>
using namespace std;

int n,k;
map<int,int> mp;
deque<int> q;

int main()
{
    scanf("%d%d",&n,&k);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(mp[x]) continue;
        mp[x]=1;
        if(q.size()<k)
        {
            q.push_front(x);
            continue;
        }
        mp[q.back()]=0;
        q.pop_back();
        q.push_front(x);
    }
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop_front();
    }
    return 0;
}
