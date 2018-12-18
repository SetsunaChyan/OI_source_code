#include <cstdio>
#include <cstring>

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	char s[1005];
	int n,l,a[26],m=0,ans=0;
	scanf("%s%d",s,&n);
	l=strlen(s);
	for(int i=0;i<26;i++)
	{
		scanf("%d",&a[i]);
		m=max(a[i],m);
	}
	for(int i=0;i<l;i++)
		ans+=(i+1)*a[s[i]-'a'];
	for(int i=0;i<n;i++)
		ans+=(l+i+1)*m;
	printf("%d",ans);
	return 0;
}
