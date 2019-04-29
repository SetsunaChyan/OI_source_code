#include <bits/stdc++.h>
using namespace std;

int n,a[200005],b[200005],nxt[200005],pre[200005],hd[200005];

int main()
{
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        b[x]++;
    }
    nxt[n]=0;pre[0]=n;
    for(int i=0;i<n;i++) nxt[i]=i+1;
    for(int i=1;i<=n;i++) pre[i]=i-1;
    for(int i=0;i<=n;i++) hd[i]=i;
    for(int i=0;i<n;i++)
    {
        int q=hd[n-a[i]];
        while(b[q]==0)
        {
            nxt[pre[q]]=nxt[q];
            pre[nxt[q]]=pre[q];
            q=nxt[q];
        }
        hd[n-a[i]]=q;
        b[q]--;
        printf("%d ",(a[i]+q)%n);
    }
    return 0;
}