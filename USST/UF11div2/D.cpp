#include <bits/stdc++.h>
using namespace std;

int n,cnt[3],mm=0x3f3f3f3f,a[100005],v1,v2,v3,qaq,sum;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),mm=min(a[i],mm);
    for(int i=0;i<n;i++)
        cnt[a[i]-mm]++,sum+=a[i]-mm;
    v1=cnt[0],v2=cnt[1],v3=cnt[2];
    if(cnt[2]==0)
    {
        printf("%d\n",n);
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        return 0;
    }
    for(int i=0;i<=n;i++)
    {
        int c=sum-n+i;
        int b=n-i-c;
        if(b>=0&&c>=0&&abs(i-cnt[0])+abs(b-cnt[1])+abs(c-cnt[2])>qaq)
        {
            qaq=abs(i-cnt[0])+abs(b-cnt[1])+abs(c-cnt[2]);
            v1=i,v2=b,v3=c;
        }
    }
    printf("%d\n",n-qaq/2);
    for(int i=0;i<v1;i++) printf("%d ",mm);
    for(int i=0;i<v2;i++) printf("%d ",mm+1);
    for(int i=0;i<v3;i++) printf("%d ",mm+2);
    return 0;
}
