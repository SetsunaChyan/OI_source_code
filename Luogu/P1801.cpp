#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> q_big;
priority_queue<int,vector<int>,greater<int> > q_small;
int m,n,a[200001],u[200001];

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&u[i]);
    sort(u+1,u+n+1);
    q_big.push(-2000000001);
    q_small.push(2000000001);
    for(int i=1,j=1;i<=m;i++)
    {
        if(a[i]<q_big.top())
        {
            q_small.push(q_big.top());
            q_big.pop();
            q_big.push(a[i]);
        }
        else
            q_small.push(a[i]);
        while(u[j]==i)
        {
            printf("%d\n",q_small.top());
            q_big.push(q_small.top());
            q_small.pop();
            j++;
            if(j>n) break;
        }
        if(j>n) break;
    }
    return 0;
}
