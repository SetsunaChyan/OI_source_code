#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans;
int n;
char s[100005];

int cal(int x)
{
	int cnt1=0,cnt2=0;
	for(int i=x;i>=1;i--)
    {
        ans++;
		if(s[i]=='1') break;
		else cnt1++;
    }
	for(int i=x;i<=n;i++)
    {
		if(cnt2>=cnt1) break;
		ans++;
		if(s[i]=='1') break;
		else cnt2++;
    }
	return min(cnt1,cnt2);
}

void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
	ans=0;
    for(int i=1;i<=n;i++) cal(i);
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
