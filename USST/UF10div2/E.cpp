#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[100005];
ll k;

int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    k--;
    sort(a,a+n);
    int fst=a[k/n],cur=0,cnt=0,sec;
    for(int i=0;i<n;i++)
    {
        if(a[i]==fst) cnt++;
        if(cnt==0) cur=i+1;
    }
    k-=(long long)cur*n;
    for(int i=0;i<n;i++)
    {
        k-=cnt;
        if(k<0)
        {
            sec=a[i];
            break;
        }
    }
    printf("%d %d",fst,sec);
    return 0;
}
