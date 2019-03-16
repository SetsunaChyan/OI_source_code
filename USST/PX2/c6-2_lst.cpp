#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sd(a) scanf("%d",&a)
const int mod=2;
int n,t;
int a[100001];
int ma[10001];
int main()
{   
    freopen("data1.out","w",stdout);
    freopen("data.in","r",stdin);
	sd(t);
	while(t--)
	{	
		memset(a,0,sizeof(a));
		memset(ma,0,sizeof(ma));
		deque<int>q;
		int ans=0;
		sd(n);
		for(int i=0;i<n;++i)
			sd(a[i]);
	    for(int i=n-1;i>=0;--i){
	    	ma[i]=max(a[i+1],ma[i+1]);
	    }
	    //for(int i=0;i<n;++i)
	    	//cout<<a[i]<<": "<<ma[i]<<endl;
	    //cout<<endl;
		for(int i=0;i<=n;++i)
		{
			if(q.empty())q.push_back(i);
			else if(a[i]>=a[q.back()])
				{
					q.push_back(i);
					ans=max(ans,q.back()-q.front());
					if(a[i]>ma[i])
						while(!q.empty())q.pop_front();
				}
			else
			{
				if(a[i]>=a[q.front()])
				{
					ans=max(ans,q.back()-q.front());
					continue;
				}
				else
				{
				    //cout<<a[i]<<endl;
					ans=max(ans,q.back()-q.front());
					while(q.size()&&a[q.front()]>a[i])q.pop_front();
					q.push_back(i);
				}
			}
		}
		printf("%d\n",ans);
	}
}