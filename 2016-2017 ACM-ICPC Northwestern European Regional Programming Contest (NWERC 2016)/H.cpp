#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100],b[100],A,B;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%1lld",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%1lld",&b[i]);
	for(int i=1;i<n;i++)
		a[i]^=a[i-1],b[i]^=b[i-1];
	for(int i=0;i<n;i++)
	{
		A<<=1,B<<=1;
		A+=a[i],B+=b[i];
	}
	printf("%lld",max(0ll,abs(A-B)-1));
	return 0;
}
