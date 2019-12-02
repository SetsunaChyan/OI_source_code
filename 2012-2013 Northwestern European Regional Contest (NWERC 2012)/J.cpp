#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int x,n ,a[N];
map<int,bool> mp;
map<int,int> cnt;

int solve(){
    mp.clear();
    cnt.clear();
    x*=1e7;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]),mp[a[i]]=1,cnt[a[i]]++;
    for(auto i:mp){
        int a=i.first;
        if(i.second==0) continue;
        if(mp[x-a]==1&&a!=x-a){
            printf("yes %d %d\n",a,x-a);
            return 0;
        }
        if(cnt[x-a]>=2&&a==x-a){
            printf("yes %d %d\n",a,x-a);
            return 0;
        }
    }
    puts("danger");

    return 0;
}

int main()
{
    while(~scanf("%d%d",&x,&n))
        solve();

    return 0;
}


