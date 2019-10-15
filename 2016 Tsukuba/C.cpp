#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,l[200005],r[200005];
pii p[100005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++)
        scanf("%d%d",&x,&y),p[i]=make_pair(x,y);
    sort(p,p+m);
    for(int i=1;i<=n;i++) l[i]=r[i]=i;
    for(int i=0;i<m;i++)
    {
        int up=min(l[p[i].second],l[p[i].second+1]),down=max(r[p[i].second],r[p[i].second+1]);
        l[p[i].second]=l[p[i].second+1]=up;
        r[p[i].second]=r[p[i].second+1]=down;
    }
    for(int i=1;i<=n;i++) printf("%d ",r[i]-l[i]+1);
    return 0;
}
