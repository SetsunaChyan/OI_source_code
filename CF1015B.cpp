#include <bits/stdc++.h>
using namespace std;

int n,cnt[26];
char s[100],t[100];
vector<int> ans;

int main()
{
    scanf("%d%s%s",&n,s,t);
    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++,cnt[t[i]-'a']--;
    for(int i=0;i<26;i++)
        if(cnt[i]) return printf("-1"),0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(t[i]==s[j])
            {
                for(int k=j;k>i;k--)
                    swap(s[k-1],s[k]),ans.push_back(k);
                break;
            }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d ",p);
    return 0;
}
