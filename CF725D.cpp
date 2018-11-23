#include <cstdio>
#include <queue>
#include<algorithm>

using namespace std;

const int MAXN = 300005;

struct node
{
	long long w, v;
} team[MAXN];
struct cmp1
{
	bool operator() (node a, node b)
	{
		return a.w - a.v > b.w - b.v || a.w - a.v == b.w - b.v && a.v < b.v;
	}
};
struct cmp2
{
	bool operator() (node a, node b)
	{
		return a.v < b.v;
	}
};
priority_queue<node, vector<node>, cmp1> q1;
priority_queue<node, vector<node>, cmp2> q2;
int n, maxrank, fly = 0;
long long rank[MAXN], me;

inline bool cmp(node a, node b)
{
	return a.v < b.v;
}

void make_pre()
{
	sort(team + 1, team + n, cmp);
	for(int i = 0; i < n - 1; i++)
		rank[i] = team[i + 1].v;
}

int findrank(long long x)
{
	int ret = n - (upper_bound(rank, rank + n, x) - rank) - fly;
	return ret ? ret : 1;
}

inline int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%I64d%I64d", &team[i].v, &team[i].w);
		if(i != 0) q1.push(team[i]); else me = team[i].v;
	}
	make_pre();
	maxrank = findrank(me);

	while(!q1.empty())
	{
		while(!q1.empty() && (q1.top()).v <= me)
		{
			q2.push(q1.top());
			q1.pop();
		}
		if(q1.empty()) break;
		node t = q1.top(); q1.pop();
		me -= t.w - t.v + 1;
		if(me < 0) break;
		fly++;
		maxrank = min(findrank(me), maxrank);
		while(!q2.empty() && (q2.top()).v > me)
		{
			q1.push(q2.top());
			q2.pop();
		}
	}

	printf("%d\n", maxrank);
	return 0;
}


/*
10
8 8
1 1
1 1
1 1
4 4
5 5
6 6
7 7
9 9
9 9

*/