#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<pair<int,int>,int> m;
int n;
long long tot=0;

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	ios::sync_with_stdio(false);
	m.clear();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		int x=0,y=0,xx=0,yy=0,l=str.length();
		for(int i=0;i<l;i++)
		{
			if(str[i]==')') xx++; else yy++;
			x=max(x,xx-yy);
		}
		xx=yy=0;
		for(int i=l-1;i>=0;i--)
		{
			if(str[i]=='(') yy++; else xx++;
			y=max(y,yy-xx);
		}
		pair<int,int> p=make_pair(x,y);
		if(m.find(p)==m.end())
			m[p]=1;
		else
			m[p]++;
	}
	map<pair<int,int>,int>::iterator it=m.begin();
	for(;it!=m.end();it++)
	{
		pair<int,int> p=it->first,q=make_pair(p.second,0);
		if(p.first!=0) continue;
		if(m.find(q)!=m.end())
			tot+=(it->second)*(long long)m[q];
	}
	cout<<tot;
	return 0;
}