#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l,z[200005];
char s[200005];

int cal(int st,int len)
{
    int ret=0;
    for(int i=st;i<st+len;i++)
        ret<<=1,ret+=s[i]-'0';
    return ret;
}

void solve()
{
    int ans=0;
    scanf("%s",s);
    l=strlen(s);
    z[0]=0;
    for(int i=1;i<l;i++)
        if(s[i-1]=='0') z[i]=z[i-1]; else z[i]=i;
    for(int len=1;len<=18;len++)
        for(int i=0;i<=l-len;i++)
        {
            if(s[i]=='0') continue;
            int k=cal(i,len);
            if(k>=len&&i+len-z[i]>=k) ans++;
        }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
