#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int n,a[N],ans[N];
int cnt[N];

void gao()
{
	vector<int> A,B;
	for(int i=1;i<N;++i)
	{
		if(cnt[i]>0)
		{
			A.push_back(cnt[i]);
			bool can=0;
			for(int j=2;i*j<N;++j)
			{
				if(cnt[i*j]>0)
				{
					can=1;
					break;
				}
			}
			if(can) B.push_back(cnt[i]);
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int sum=A.size();
	int i=0,j=0,sa=0,sb=0;
	for(int k=0;k<=n;++k)
	{
		while(i<A.size()&&sa+A[i]<=k)
			sa+=A[i],i++;
		while(j<B.size()&&sb+B[j]<=k)
			sb+=B[j],j++;
		printf("%d ",min(sum-i+1,sum-j));
	}
}

int main()
{
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),cnt[a[i]]++;
	gao();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6
3 4 1 2 1 2
*/
