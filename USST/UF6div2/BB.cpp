    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const ll mod=1e9+7;
    const ll mod2=mod+mod;
    const ll mod3=mod2+mod;
    int n,l[705],r[705];
    int L[]={0,0,0,1,1,1,2,2,2};
    int R[]={0,1,2,0,1,2,0,1,2};
    char s[705];
    stack<int>st;
    struct node
    {
    	ll v[9];
    }h[702][702];
    node f(int l,int r)
    {
    	if(h[l][r].v[0]!=-1)return h[l][r];
    	node ans;
    	for(int i=0;i<9;i++)ans.v[i]=0;
    	if(l>=r)for(int i=0;i<9;i++)ans.v[i]=1;
    	else if(l+1==r)for(int i=0;i<9;i++)ans.v[i]=(i/3==0&&i%3||i%3==0&&i/3);
    	else if(::r[l]==r)
    	{
    		node t=f(l+1,r-1);
    		ll sum=0;
    		for(int i=0;i<9;i++)
    			sum=(sum+t.v[i])%mod;
    		ans.v[1]=(sum-t.v[1]-t.v[4]-t.v[7]+mod3)%mod;
    		ans.v[2]=(sum-t.v[2]-t.v[5]-t.v[8]+mod3)%mod;
    		ans.v[3]=(sum-t.v[3]-t.v[4]-t.v[5]+mod3)%mod;
    		ans.v[6]=(sum-t.v[6]-t.v[7]-t.v[8]+mod3)%mod;
    	}
    	else
    	{
    		node t1=f(l,::r[l]),t2=f(::r[l]+1,r);
    		for(int i=0;i<9;i++)
    			for(int j=0;j<9;j++)
    				for(int k=0;k<9;k++)
    					if(L[i]==L[j]&&R[i]==R[k]&&(R[j]!=L[k]||R[j]==0&&L[k]==0))
    						ans.v[i]=(ans.v[i]+t1.v[j]*t2.v[k])%mod;
    	}
    	//for(int i=0;i<4;i++)ans.v[i]%=mod;
    	printf("%d %d\n",l,r);
    	for(int i=0;i<9;i++)
    		printf("%lld ",ans.v[i]);
    	puts("");
    	return h[l][r]=ans;
    }
    int main()
    {
    	scanf("%s",s+1);
    	n=strlen(s+1);
    	for(int i=1;i<=n;i++)
    		for(int j=i;j<=n;j++)
    			memset(h[i][j].v,-1,sizeof(h[i][j].v));
    	for(int i=1;i<=n;i++)
    		if(s[i]=='(')
    			st.push(i);
    		else
    			l[i]=st.top(),st.pop();
    	for(int i=1;i<=n;i++)
    		r[l[i]]=i;
    	node t=f(1,n);
    	ll ans=0;
    	for(int i=0;i<9;i++)
    		ans=(ans+t.v[i])%mod;
    	printf("%lld\n",ans);
    	for(int i=1;i<=n;i++)
    		if(s[i]==')')
    		{
    			t=f(l[i],i);
    			ll sum=0;
    			for(int i=0;i<9;i++)
    				sum=(sum+t.v[i])%mod;
    			printf("%d~%d %lld\n",l[i],i,sum);
    		}
    	return 0;
    }

