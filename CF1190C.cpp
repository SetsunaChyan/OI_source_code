#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,p[100005],k,m,ans=0,last=-1,delt=0,del=0;

int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=0;i<m;i++)
        scanf("%lld",&p[i]),p[i]--;
    for(int i=0;i<m;i++)
    {
        if((p[i]-del)/k!=last)
        {
            ans++;
            del=delt;
            last=(p[i]-del)/k;
        }
        delt++;
    }
    printf("%lld",ans);
    return 0;
}
