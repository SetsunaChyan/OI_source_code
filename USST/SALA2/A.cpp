#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
pii a[1000];
vector<int> v;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=make_pair(x,i+1);
    }
    sort(a,a+n);
    v.push_back(a[0].second);
    for(int i=1;i<n;i++)
        if(a[i].first!=a[i-1].first)
            v.push_back(a[i].second);
    if(v.size()<m) printf("NO");
    else
    {
        printf("YES\n");
        for(int i=0;i<m;i++) printf("%d ",v[i]);
    }
    return 0;
}
