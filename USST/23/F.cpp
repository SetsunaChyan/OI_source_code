#include <iostream>
#include <string>

using namespace std;

int n;

void f(string s,int dep)
{
	if(dep==n)
	{
		cout<<s<<endl;
		return;
	}
	string t="A";
	t[0]=t[0]+dep;
	s=s+t+s;
	f(s,dep+1);
}

int main()
{
	string s="A";
	cin>>n;
	f(s,1);
	return 0;
}
