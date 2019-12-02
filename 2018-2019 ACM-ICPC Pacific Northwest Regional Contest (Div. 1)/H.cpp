#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int ans=0;
bool b[N+5]={false};
int prime[N+5];
int cnt=0,n;
int main()
{
    int i,j;
    for (i=2;i<=N;i++)
        if (!b[i]) {
            prime[++cnt]=i;
            for (j=i+i;j<=N;j+=i)
                if (!b[j]) b[j]=true;
        }
    cin>>n;
    while (n>=4) {
        for (i=1;i<=cnt;i++)
            if (!b[n-prime[i]]) {
                n=n-prime[i]-prime[i];
 //               cout<<prime[i]<<' '<<n<<endl;
                ans++;
                break;
            }
    }
    cout<<ans<<endl;
    return 0;
}
