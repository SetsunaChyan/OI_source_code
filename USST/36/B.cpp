#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[100005];
int n;

inline bool cmp(string a,string b){return a+b>b+a;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
		cout<<s[i];		
	return 0;
}
