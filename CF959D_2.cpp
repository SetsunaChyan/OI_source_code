#include <bits/stdc++.h>
using namespace std;

const int N=1500000;
int n,vis[1500005],limit=1,cur=2;
vector<int> v[1500005];

void seive()
{
    for(int i=2;i<=N;i++)
        if(v[i].size()==0)
            for(int j=i;j<=N;j+=i) v[j].push_back(i);
}

int main()
{
    seive();
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        if(!limit)
        {
            while(vis[cur]) cur++;
            for(int j=cur;j<=N;j+=cur) vis[j]=1;
            printf("%d ",cur);
            cur++;
            continue;
        }
        if(!vis[x])
        {
            printf("%d ",x);
            for(auto p:v[x])
                for(int j=p;j<=N;j+=p) vis[j]=1;
            continue;
        }
        limit=0;
        for(int j=x;;j++)
            if(!vis[j])
            {
                printf("%d ",j);
                for(auto p:v[j])
                    for(int k=p;k<=N;k+=p) vis[k]=1;
                break;
            }
    }
    return 0;
}
