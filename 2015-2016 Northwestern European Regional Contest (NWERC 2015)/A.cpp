#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,ans;
pii p[300005];
priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		p[i]={x,x+y};
	}
    sort(p,p+n);
    for(int i=0;i<n;i++) pq.push(p[i].second);
    for(int i=0;i<n;i++)
    {
        while(!pq.empty()&&pq.top()+m<p[i].first) pq.pop();
        if(pq.empty()) continue;
        if(pq.top()<=p[i].first&&pq.top()+m>=p[i].first) ans++,pq.pop();
    }
    printf("%d",ans);
	return 0;
}
/*
3 5
1 5
6 3
14 6

5 10
2 6
1 2
17 7
3 9
15 6
*/
