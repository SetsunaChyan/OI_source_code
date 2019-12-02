#include <bits/stdc++.h>
using namespace std;

int n,a[100][2],flag,tot;
char s[10000];

int main()
{
	freopen("boolean.in","r",stdin);
	freopen("boolean.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='|') continue;
		if(s[i]=='~')
		{
			flag=1;
			continue;
		}
		if(s[i]>='a'&&s[i]<='z')
			a[s[i]-'a'][flag]++;
		else
			a[s[i]-'A'+26][flag]++;
		flag=0;
	}
	flag=0;
	for(int i=0;i<26*2;i++)
	{
		if(a[i][0]&&a[i][1]) flag=1;
		if(a[i][0]+a[i][1]) tot++;
	}
	long long ans=1;
	for(int i=0;i<tot;i++)
		ans<<=1;
	if(!flag) ans--;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
