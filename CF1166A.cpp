#include <bits/stdc++.h>
using namespace std;

int cnt[26],ans=0,n;
char s[1000];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s),cnt[s[0]-'a']++;
    for(int i=0;i<26;i++)
    {
        int k=cnt[i]-cnt[i]/2;
        ans+=cnt[i]/2*(cnt[i]/2-1)/2+k*(k-1)/2;
    }
    printf("%d",ans);
    return 0;
}