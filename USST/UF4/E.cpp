#include <bits/stdc++.h>
using namespace std;

int n,a[100005],mm=0x3f3f3f3f,mx;
int cnt[100005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),mm=min(mm,a[i]),mx=max(mx,a[i]);
    sort(a,a+n);
    for(int i=1;i<n;i++)
        if(a[i]-a[i-1]>=2)
        {
            printf("NO");
            return 0;
        }
    mx-=mm;
    for(int i=0;i<n;i++) cnt[a[i]-mm]++;
    cnt[mx]--;int now=mx;
    for(int i=1;i<n;i++)
    {
        if(cnt[now-1]) now=now-1,cnt[now]--;
        else if(cnt[now+1]) now=now+1,cnt[now]--;
        else
        {
            printf("NO");
            return 0;
        }
    }
    if(mx-now==1) printf("YES");
    else printf("NO");
    return 0;
}
