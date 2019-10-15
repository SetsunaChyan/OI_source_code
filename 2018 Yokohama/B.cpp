#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[50005],ans;
set<ll> s;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]),s.insert(a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            ll d=a[j]-a[i],now=a[i];
            if(s.find(a[i]+ans*d)==s.end()) continue;
            while(s.find(now+d)!=s.end()) now+=d;
            ans=max(ans,(now-a[i])/d+1);
        }
    printf("%lld",ans);
    return 0;
}

/*
6
0 1 3 5 6 9
7
1 4 7 3 2 6 5
5
1 2 4 8 16
*/
