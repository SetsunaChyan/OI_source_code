#include <cstdio>
#include <queue>

using namespace std;

char s[10];
int k;
struct node
{
	int num,period,time;
	node(int n,int p,int t):num(n),period(p),time(t){}
	bool operator < (const node &b) const
	{
		return time>b.time||time==b.time&&num>b.num;
	}
};

priority_queue<node> q;

int main()
{
	while(~scanf("%s",s),s[0]=='R')
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q.push(node(x,y,y));
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		node temp=q.top();
		q.pop();
		printf("%d\n",temp.num);
		temp.time+=temp.period;
		q.push(temp);
	}
	return 0;
}