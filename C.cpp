#include <bits/stdc++.h>
using namespace std;

int cnt[1005],n,m[30][30];
deque<int> v1,v2,v4;

int main()
{
    scanf("%d",&n);
    for(int i=0,x;i<n*n;i++)
        scanf("%d",&x),cnt[x]++;
    for(int i=1;i<=1000;i++)
    {
        if(!cnt[i]) continue;
        while(cnt[i]>=4) cnt[i]-=4,v4.push_back(i);
        while(cnt[i]>=2) cnt[i]-=2,v2.push_back(i);
        if(cnt[i]==1) v1.push_back(i);
    }
    if(n&1)
    {
        if(v1.size()>1||v2.size()>n/2*2) return printf("NO"),0;
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n/2;j++)
                m[i][j]=m[n-i-1][j]=m[i][n-j-1]=m[n-i-1][n-j-1]=v4[0],v4.pop_front();
        while(!v4.empty())
        {
            v2.push_back(v4.front());
            v2.push_back(v4.front());
            v4.pop_front();
        }
        for(int i=0;i<n/2;i++)
            m[n/2][i]=m[n/2][n-i-1]=v2.front(),v2.pop_front();
        for(int i=0;i<n/2;i++)
            m[i][n/2]=m[n-i-1][n/2]=v2.front(),v2.pop_front();
        m[n/2][n/2]=v1.front();
    }
    else
    {
        if(v1.size()||v2.size()) return printf("NO"),0;
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n/2;j++)
                m[i][j]=m[n-i-1][j]=m[i][n-j-1]=m[n-i-1][n-j-1]=v4.front(),v4.pop_front();
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
    return 0;
}
