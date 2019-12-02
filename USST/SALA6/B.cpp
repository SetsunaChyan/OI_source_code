#include <bits/stdc++.h>
using namespace std;

int n,a[100005],num,flg,x,cnt[100005];
set<int> s;

int main()
{
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),cnt[a[i]]++,s.insert(a[i]);
    for(int i=0;i<=100000;i++)
        if(cnt[i]>=2) return printf("0"),0;
    for(int i=0;i<n;i++)
    {
        s.erase(a[i]);
        if(s.find(a[i]&x)!=s.end()) return printf("1"),0;
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        s.erase(a[i]);
        if(s.find(a[i]&x)!=s.end()) return printf("2"),0;
        s.insert(a[i]&x);
        s.insert(a[i]);
    }
    printf("-1");
    return 0;
}
