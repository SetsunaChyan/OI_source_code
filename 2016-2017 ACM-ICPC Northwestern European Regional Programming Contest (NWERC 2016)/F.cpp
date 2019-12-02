#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[1000005],b[1000005];

bool check(int x)
{
	vector<int> A,B;
	for(int i=0;i<n;i++)
	{
		if(a[i]>x) A.push_back(a[i]);
		if(b[i]>x) B.push_back(b[i]);
	}
	if(A.size()%2||B.size()%2) return false;
	for(int i=0;i<A.size();i+=2)
		if(A[i]!=A[i+1]) return false;
	for(int i=0;i<B.size();i+=2)
		if(B[i]!=B[i+1]) return false;
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
		scanf("%d",b+i);
	int l=0,r=1000000000;
	while(l<r)
	{
		int m=l+r>>1;
		if(check(m)) r=m; else l=m+1;
	}
	printf("%d",l);
	return 0;
}
