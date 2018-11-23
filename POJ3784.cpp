#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> gr;
priority_queue<int,vector<int>,greater<int> > sm;
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	int _;
	scanf("%d ",&_);
	while(_--)
	{
		while(!sm.empty()) sm.pop();
		while(!gr.empty()) gr.pop();
		int x,tca;
		scanf("%d%d%d",&tca,&n,&x);
		printf("%d %d\n",tca,n/2+1);
		gr.push(x);
		printf("%d ",x);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&x);  
			if(x<gr.top())
			{
				if(gr.size()==i/2+1)
				{
					sm.push(gr.top());
					gr.pop();
				}
				gr.push(x);
			}
			else
			{
				if(gr.size()<i/2+1)
				{
					if(x>sm.top())
					{
						gr.push(sm.top());
						sm.pop();
						sm.push(x); 
					}
					else
						gr.push(x);
				}
				else
					sm.push(x);
			}
			if(!(i&1)) 
			{
				if(i/2%10==0) printf("\n");
				printf("%d ",gr.top());
			}
		}
		printf("\n");
	}
	return 0;
}