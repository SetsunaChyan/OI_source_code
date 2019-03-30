#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string s[105];
int n,fa[105];

bool check(string a,string b)
{
	int la=a.length(),lb=b.length(),flag;
	for(int i=0;i<la-lb+1;i++)
	{
		flag=1;
		for(int j=0;j<lb;j++)
			if(b[j]!=a[i+j]) 
			{
				flag=0;
				break;
			}
		if(flag) return true;
	}
	return false;
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void uni(int a,int b)
{
	a=find(a);
	b=find(b);
	fa[b]=a;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		fa[i]=i;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(find(i)!=find(j)&&check(s[i],s[j]))
				uni(i,j);
		}
	int root=find(fa[0]);
	for(int i=1;i<n;i++)
		if(find(i)!=root)
		{
			printf("YES");
			return 0;
		}
	printf("NO");
	return 0;
}
