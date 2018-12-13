#include <cstdio>
#include <cstring>
#include <memory.h>

int cnt[26];

inline void swap(char &a,char &b){char t=a;a=b;b=t;}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		int l,k=0,ans=0;
		char s[8001];
		memset(cnt,0,sizeof(cnt));
		scanf("%s",s);
		l=strlen(s);
		for(int i=0;i<l;i++)
			cnt[s[i]-'a']++;
		for(int i=0;i<26;i++)
			if(cnt[i]&1) k++;
		if(k>1&&(l&1)||!(l&1)&&k>0)
		{
			printf("Impossible\n");
			continue;
		}
		for(int i=0;i<l/2;i++)
		{
			if(s[i]==s[l-i-1]) continue;
			int q=l-i-1,r=i;
			for(int j=i;j<l-i;j++)
				if(s[j]==s[l-i-1])
				{
					q=j;
					break;
				}
			for(int j=l-i-1;j>=i;j--)
				if(s[j]==s[i])
				{
					r=j;
					break;
				}
			if(q-i<(l-i-1)-r)
				for(int j=q;j>i;j--)
				{
					swap(s[j],s[j-1]);
					ans++;
				}
			else
				for(int j=r;j<l-i-1;j++)
				{
					swap(s[j],s[j+1]);
					ans++;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}