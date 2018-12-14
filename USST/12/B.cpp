#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

pair<string,int> p[101];
map<string,int> s;

inline bool cmp(pair<string,int> a,pair<string,int> b)
{
	return a.second>b.second||(a.second==b.second&&a.first<b.first);
}

int main()
{
	s.clear();
	int n,tot=0;
	string str[101];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		if(s.find(str[i])==s.end())
		{
			s[str[i]]=1;
		}	
		else	
			s[str[i]]++;
	}
	for(int i=0;i<n;i++)
		p[i]=make_pair(str[i],s[str[i]]);
	sort(p,p+n,cmp);
	int sum=0;
	for(int i=0;i<n;i++)
		if(!i||p[i].first!=p[i-1].first) sum++; 
	cout<<sum<<endl;
	for(int i=0;i<n;i++)
	{
		int k=0;
		if(!i||p[i].second!=p[i-1].second)
			cout<<p[i].second<<endl;
		if(!i||p[i].first!=p[i-1].first)
			cout<<p[i].first<<endl;
	}
	return 0;
}