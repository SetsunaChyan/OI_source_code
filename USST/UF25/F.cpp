#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int s,n;
pii p[1005];

int main()
{
    scanf("%d%d",&s,&n);
    for(int i=0,x,y;i<n;i++)
        scanf("%d%d",&x,&y),p[i]={x,y};
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        if(s<=p[i].first)
        {
            printf("NO");
            return 0;
        }
        s+=p[i].second;
    }
    printf("YES");
    return 0;
}
