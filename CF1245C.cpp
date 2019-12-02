#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int N;
ll f[100005];
char s[100005];

int main()
{
    scanf("%s",s);
    N=strlen(s);
    f[0]=f[1]=1;
    for(int i=2;i<=N;i++) f[i]=f[i-1]+f[i-2],f[i]%=mod;
    f[0]=0;
    ll u=0,n=0,ans=1,cur;
    for(int i=0;i<N;)
        if(s[i]=='u'||s[i]=='n')
        {
            cur=i;
            while(i<N)
            {
                if(s[i]!=s[cur]) break;
                i++;
            }
            if(i-cur-1>0) ans*=f[i-cur]%mod,ans%=mod;
            continue;
        }
        else if(s[i]=='w'||s[i]=='m')
        {
            ans=0;
            break;
        }
        else
            i++;
    printf("%lld",ans);
    return 0;
}
