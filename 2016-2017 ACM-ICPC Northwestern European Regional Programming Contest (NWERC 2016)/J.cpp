#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n,q,s;
	ll sumd=0;
	ll suma=0;
	int tar[105]={0};
	ll qsize[35]={0};
	ll qleft[35]={0};
	ll buffer=0;

	scanf("%d %d %d",&n,&q,&s);
	for(int i=1;i<=s;i++)
	{
		scanf("%d",tar+i);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",qsize+i);
		qleft[i]=qsize[i];
	}
	ll par,tmp;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&tmp);
		sumd+=tmp;
		ll qthis[35]={0};
		for(int j=1;j<=s;j++)
		{
			scanf("%lld",&par);
			qthis[tar[j]]+=par;
			suma+=par;
		}
		for(int j=1;j<=q;j++)
		{
			if(qthis[j]>qsize[j])
			{
				cout<<"impossible";
				return 0;
			}
		}
		for(int j=1;j<=q;j++)
		{
			qleft[j]-=qthis[j];
			if(qleft[j]<0)
			{
				buffer+=qleft[j];
				qleft[j]=0;
				if(buffer<0)
				{
					cout<<"impossible";
					return 0;
				}
			}
		}
		buffer+=tmp;
	}
	if(sumd>=suma)
	{
		cout<<"possible";
	}
	else
	{
		cout<<"impossible";
	}

	return 0;
}
