#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[400005],qaq;
ll ans;
vector<int> pos[21];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),pos[a[i]].push_back(i);
    for(int i=0;i<21;i++)
    {
        if(pos[i].size()==0) continue;
        int k=pos[i][pos[i].size()/2];
        int cnt=0;
        for(auto j:pos[i])
        {
            if(j<k) ans+=k-j-1-cnt;
            cnt++;
            if(j>k) ans+=j-k-1-((int)pos[i].size()-cnt);
        }
        ans--;
        //if((int)pos[i].size()%2==1) ans-=2;
    }
    printf("%lld",ans);
    return 0;
}
