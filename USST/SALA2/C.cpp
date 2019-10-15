#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int n,len[200005],sum[200005];
vector<int> a[200005];
set<piii> s;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",len+i);
        for(int j=0,x;j<len[i];j++)
            scanf("%d",&x),a[i].push_back(x),sum[i]+=x;
    }
    for(int i=0;i<len[0];i++)
        s.insert(make_pair(sum[0]-a[0][i],make_pair(0,i)));
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<len[i];j++)
        {
            auto it=s.lower_bound(make_pair(sum[i]-a[i][j],make_pair(0,0)));
            if(it==s.end()) continue;
            piii p=*it;
            if(p.first==sum[i]-a[i][j])
            {
                printf("YES\n");
                printf("%d %d\n%d %d\n",p.second.first+1,p.second.second+1,i+1,j+1);
                return 0;
            }
        }
        for(int j=0;j<len[i];j++)
            s.insert(make_pair(sum[i]-a[i][j],make_pair(i,j)));
    }
    printf("NO");
    return 0;
}
