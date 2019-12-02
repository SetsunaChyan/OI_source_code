#include <bits/stdc++.h>
using namespace std;

int n,id[26],x[26],vis[26],cnt[20][20],ans,state;
char s[1000005];

int main()
{
	freopen("consonant.in","r",stdin);
	freopen("consonant.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i='a';i<='z';i++)
		if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='w'||i=='y')
			x[i-'a']=1;
		else
			id[i-'a']=1;
	for(int i=1;i<26;i++) id[i]+=id[i-1];
	for(int i=0;i<n-1;i++)
	{
		if(x[s[i]-'a']||x[s[i+1]-'a']) continue;
		cnt[id[s[i]-'a']][id[s[i+1]-'a']]++;
	}
	for(int i=0;i<(1<<20);i++)
	{
		memset(vis,0,sizeof(vis));
		int t=i,c=0,tmp=0;
		while(t)
		{
			if(t&1) vis[c]++;
			t>>=1;
			c++;
		}
		for(int I=0;I<20;I++)
			for(int J=0;J<20;J++)
				if(vis[I]+vis[J]==1) tmp+=cnt[I][J];
		if(tmp>ans) ans=tmp,state=i;
	}
	memset(vis,0,sizeof(vis));
	int t=state,c=0;
	while(t)
	{
		if(t&1) vis[c]++;
		t>>=1;
		c++;
	}
	for(int i=0;i<n;i++)
	{
		if(x[s[i]-'a'])
		{
			printf("%c",s[i]);
			continue;
		}
		if(vis[id[s[i]-'a']])
			printf("%c",s[i]-'a'+'A');
		else
			printf("%c",s[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
