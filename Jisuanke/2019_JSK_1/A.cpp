#include <bits/stdc++.h>
using namespace std;

int deg[50005],maxx=0,mm=-1,ans=0;
vector<int> e[50005];
inline bool cmp(int a,int b){return a>b;}

int main()
{
    memset(deg,0,sizeof(deg));
    int n;
    scanf("%d",&n);
    if(n<=2) {printf("0");return 0;}
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        deg[x]++;
        deg[y]++;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(maxx<deg[i])
        {
            maxx=deg[i];
            mm=i;
        }
    ans+=maxx;
    for(auto p:e[mm]) deg[p]--;
    deg[mm]=-1,maxx=0;
    for(int i=1;i<=n;i++)
        maxx=max(maxx,deg[i]);
    printf("%d",ans-1+maxx);
	return 0;
}