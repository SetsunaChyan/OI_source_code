#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define sd(a) scanf("%d",&a)

int a[100],b[100];

int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int j=0;j<t;j++)
	{
		for(int i=0;i<n;i++)
			b[i]=a[i];
		for(int i=0;i<n;i++)
			if(b[i])
			{
				if(i) a[i-1]=1-a[i-1];
				if(i!=n-1) a[i+1]=1-a[i+1];
			}
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}