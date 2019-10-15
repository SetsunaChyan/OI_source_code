#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100005],n,r,c;

void solve()
{
    c=0;
    int ans=0;
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++)
        if(a[i]-c<=0) continue;
        else
        {
            c+=r,ans++;
            while(i<n&&a[i]==a[i+1]) i++;
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
