#include <cstdio>
#include <memory.h>

int n,m,k,a[10005],b[10005];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        memset(b,0,sizeof b);
        memset(a,0,sizeof a);
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(i<n/2) a[x]++;
            b[x]++;
        }
        int ans=0;
        for(int i=0;i<m;i++)
            ans+=min(a[i+1],b[i+1]/k);
        printf("%d\n",ans);
    }
    return 0;
}