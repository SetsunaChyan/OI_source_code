#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,r,cur;
pii p[100005];
set<int> s[200005];
vector<int> v[200005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        p[i]=make_pair(x,i+1);
    }
    for(int i=1;i<=2*n;i++) v[i].push_back(0);
    sort(p,p+n,greater<pii>());
    cur=1;
    r=p[0].first+1;
    int i;
    for(i=0;i<n;i++)
    {
        int now=p[i].second;
        int dis=p[i].first;
        while(cur<=r&&v[cur][0]) cur++;
        if(cur>r) break;
        v[cur][0]=2*now-1;
        if(cur+dis>r)
        {
            r=cur+dis;
            v[r][0]=2*now;
        }
        else
        {
            if(v[cur+dis][0]==0) v[cur+dis][0]=2*now;
            else v[cur+dis-1].push_back(2*now);
        }
    }
    for(;i<n;i++)
    {
        int now=p[i].second;
        int dis=p[i].first;
        if(dis==1)
        {
            v[++r][0]=now*2-1;
            v[++r][0]=now*2;
            continue;
        }
        v[1].push_back(now*2-1);
        if(v[dis][0]==0) v[dis][0]=now*2;
        else v[dis-1].push_back(now*2);
    }
    for(int i=1;i<=r;i++)
    {
        if(i!=r) printf("%d %d\n",v[i][0],v[i+1][0]);
        for(int j=1;j<v[i].size();j++)
            printf("%d %d\n",v[i][0],v[i][j]);
    }
}
