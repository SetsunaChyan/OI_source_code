#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

priority_queue<int> pq;
queue<int> q;
stack<int> s;
int n,is_q,is_pq,is_s;

int main()
{
	while(~scanf("%d",&n))
	{
		while(!pq.empty()) pq.pop();
		while(!q.empty()) q.pop();
		while(!s.empty()) s.pop();
		is_q=1;is_s=1;is_pq=1;
		for(int i=0;i<n;i++)
		{
			int opt,x;
			scanf("%d%d",&opt,&x);
			if(is_q)
				if(opt==1) q.push(x);
				else
					if(q.empty()) is_q=0;
					else
					{
						int y=q.front();
						q.pop();
						if(x!=y) is_q=0;
					}
			if(is_s)
				if(opt==1) s.push(x);
				else
					if(s.empty()) is_s=0;
					else
					{
						int y=s.top();
						s.pop();
						if(x!=y) is_s=0;
					}
			if(is_pq)
				if(opt==1) pq.push(x);
				else
					if(pq.empty()) is_pq=0;
					else
					{
						int y=pq.top();
						pq.pop();
						if(x!=y) is_pq=0;
					}
		}
		if(is_pq+is_s+is_q>1) printf("not sure\n");
		else if(is_pq) printf("priority queue\n");
		else if(is_s) printf("stack\n");
		else if(is_q) printf("queue\n");
		else printf("impossible\n");
	}
	return 0;
}