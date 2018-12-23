#include <cstdio>

typedef long long ll;
const int maxn=5e5+50;
ll n,k,pre=1,ans=0;
char s1[maxn],s2[maxn];

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    scanf("%lld%lld",&n,&k);
    scanf("%s%s",s1,s2);
    for(int i=0,j=n;i<n;i++,j--)
    {
        if(k<=0) break;
        ll temp;
        if(s1[i]==s2[i])
            temp=pre-1;
        else if(s1[i]<s2[i])
            temp=pre;
        else
            temp=pre-2;
        pre+=temp;
        if(i) temp=min(k,temp); else temp=min(k,pre);
        k-=temp;
        ans+=temp*j;
    }
    printf("%lld",ans);
    return 0;
}