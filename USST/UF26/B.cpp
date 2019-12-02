#include <bits/stdc++.h>
using namespace std;

char s[100005];
int ans=0x3f3f3f3f;
vector<int> a[26];

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<26;i++) a[i].push_back(0);
    for(int i=0;i<n;i++)
        a[s[i]-'a'].push_back(i+1);
    for(int i=0;i<26;i++) a[i].push_back(n+1);
    for(int i=0;i<26;i++)
    {
        int tmp=0;
        for(int j=1;j<a[i].size();j++) tmp=max(a[i][j]-a[i][j-1],tmp);
        //printf("%d\n",tmp);
        ans=min(tmp,ans);
    }
    printf("%d",ans);
    return 0;
}
