#include <cstdio>
#include <algorithm>

using namespace std;

int d[100005],l,r,n,b;

bool check(int x)
{
    int last=-0x3f3f3f3f,g=0;
    for(int i=0;i<n;i++)
        if(d[i]-last>=x)
        {
            last=d[i];
            g++;
        }
    if(g>=b) return true; else return false;
}

int main()
{
    scanf("%d%d",&n,&b);
    for(int i=0;i<n;i++)
        scanf("%d",&d[i]);
    sort(d,d+n);
    l=1,r=0x3f3f3f3f;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(check(m)) l=m+1; else r=m;
    }
    printf("%d",l-1);
    return 0;
}