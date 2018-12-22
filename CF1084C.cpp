#include <cstdio>
#include <cstring>

typedef long long ll;
char s[100005];
const ll mod=1e9+7;
ll a=0,b=0,n,ans=0,l=0;

int main()
{
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='a'||s[i]=='b')
            s[l++]=s[i];
    n=l;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
            ans=(ans+b+1)%mod;
        else if(i&&s[i-1]=='a'&&s[i]=='b')
            b=ans;
    }
    printf("%lld",ans);
    return 0;
}
