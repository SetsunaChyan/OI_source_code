#include <bits/stdc++.h>

using namespace std;

stack<int> s;
vector<set<int> > setcache;
map<set<int>,int> m;

int ID(set<int> x)
{
	if(m.count(x)) return m[x];
	setcache.push_back(x);
	return m[x]=setcache.size()-1;
}

int main()
{
	int _,n;
	scanf("%d",&_);
	while(_--)
	{
		while(!s.empty()) s.pop();
		m.clear();
		setcache.clear();
		scanf("%d",&n);
		while(n--)
		{
			char opt[50];
			scanf("%s",opt);
			if(opt[0]=='P')
			{
				set<int> es;
				s.push(ID(es));
			}
			else if(opt[0]=='D')
			{
				s.push(s.top());
			}
			else 
			{
				set<int> A=setcache[s.top()];s.pop();
				set<int> B=setcache[s.top()];s.pop();
				set<int> X;
				if(opt[0]=='U') set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(X,X.begin()));
				else if(opt[0]=='I') set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(X,X.begin()));
				else X=B,X.insert(ID(A));
				s.push(ID(X));
			}
			printf("%d\n",setcache[s.top()].size());
		}
		printf("***\n");
	}
	return 0;
}