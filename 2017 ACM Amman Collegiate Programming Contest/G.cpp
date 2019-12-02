#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2003;
ll a[maxn],sum[maxn];
ll GCD(ll a,ll b)
{
    return b==0?a:GCD(b,a%b);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        ll lcm,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }

        for(int i=1;i<n;i++) {
            lcm=a[i];
            for(int j=i+1;j<=n;j++) {
                lcm=lcm/GCD(lcm,a[j])*a[j];
                if(lcm>sum[n]) break;
                if((sum[j]-sum[i-1])%lcm==0) ans++;
             }
        }
        ans+=(ll)n;
        /*for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) {
            cout<<lcm[i][j]<<" ";
            if(j==n) cout<<"\n";
        }
        cout<<endl;*/
        //cout<<"Ad";
        /*for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) {
            //cout<<"i= "<<i<<endl;
            if(lcm[i][j]==-1) break;
            //cout<<lcm[i][j]<<endl;
            if((sum[j]-sum[i-1])%lcm[i][j]==0) ans++;
            //cout<<"asd "<<i<<" "<<j<<endl;
        }*/

        printf("%lld\n",ans);

    }
    return 0;
}
