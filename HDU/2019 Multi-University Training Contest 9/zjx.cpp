#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 104;
ll w[maxn],vis[100];
vector<ll> v;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,flag=0,x,minv=1100000004,maxv=0,a=0,b=0,c=0;
		scanf("%lld",&n);
		v.clear();
		memset(vis,0,sizeof(vis));
		for(ll i=1;i<=n;i++) {
			scanf("%lld",&x);
			if(x%10!=0)
				flag=1;
			if(flag) continue;
			w[i]=x/10;
			if(w[i]%10) vis[w[i]%10]=1;
			maxv=max(maxv,x/100);
			minv=min(minv,x/100);
		}

		if(flag) {
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=9;i++) if(vis[i]) v.push_back(i);
		ll ans=0,tmp,now=1000;
		for(ll i=2;i>=0;i--)
		{
			for(ll j=5;j>=0;j--)
			{
				for(ll k=9;k>=0;k--)
				{
					for(ll l=0;l<v.size();l++)
					{
						flag=0;
						for(ll u=0;u<=i;u++)
						{
							for(ll p=0;p<=j;p++)
							{
								for(ll q=0;q<=k;q++)
								{
									if(q+p*2+u*5==v[l]) {flag=1;break;	}
								}
								if(flag) break;
							}
							if(flag) break;
						}
						if(!flag) break;
					}
					//if(flag!=1) cout<<i<<" "<<j<<" "<<k<<"\n";
					if(flag)
					{
						if(i+j+k<now)
						{
							a=i,b=j,c=k;
							now=a+b+c;
							continue;
						}
					}
				}
			}
		}
		//cout<<a<<" "<<b<<" "<<c<<endl;
		ans=ans+a+b+c;
		memset(vis,0,sizeof(vis));
		for(ll i=0;i<=a;i++) for(ll j=0;j<=b;j++) for(ll k=0;k<=c;k++)
		{
			tmp=i*5+2*j+k;
			if(tmp%10==0) vis[tmp]=1;
		}
		maxv=0;
		ll cnt=0;
		for(ll i=1;i<=9;i++) if(vis[i*10]) cnt++;
		if(cnt>0)
		{
			if(cnt==1)for(ll i=1;i<=n;i++)
				if(w[i]%10==0) maxv=max(maxv,(w[i]/10)-1);
				else maxv=max(w[i]/10,maxv);
			else for(ll i=1;i<=n;i++)
				if(w[i]%10==0) maxv=max(maxv,((w[i]/10)>=2?(w[i]/10-2):(w[i]/10-1)));
				else maxv=max(maxv,w[i]);
		}
		else {
			for(ll i=1;i<=n;i++)
				maxv=max(maxv,w[i]/10);
		}
		//for(ll i=1;i<=9;i++) if(vis[i*10]) maxv--;
		if(maxv>0) ans+=maxv;
		printf("%lld\n",ans);
	}
	return 0;
}

/*
12
4
20 50 30 70
10
10 20 30 40 50 60 70 80 90 100
11
10 20 30 40 50 60 70 80 90 100 200
12
10 20 30 40 50 60 70 80 90 100 200 220
5
10 20 30 40 50
5
100 200 300 400 500
1
1
5
30 200 300 400 1000000000
20
10 20 30 40 50 60 70 80 90 100 110 120 130 140 150 160 170 180 190 200
3
30 90 840
*/
