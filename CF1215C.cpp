#include <bits/stdc++.h>
using namespace std;

int n;
char s[200005],t[200005],tot;
int cnt[2];
vector<int> ab,ba;
vector<pair<int,int>> ans;

int main()
{
    scanf("%d%s%s",&n,s,t);
    for(int i=0;i<n;i++)
    {
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']++;
        if(s[i]=='a'&&t[i]=='b') ab.push_back(i);
        if(s[i]=='b'&&t[i]=='a') ba.push_back(i);
    }
    for(int i=0;i<2;i++)
    {
        if(cnt[i]%2)
        {
            printf("-1");
            return 0;
        }
    }
    for(int i=1;i<ab.size();i+=2)
    {
        tot++;
        ans.emplace_back(ab[i],ab[i-1]);
    }
    for(int i=1;i<ba.size();i+=2)
    {
        tot++;
        ans.emplace_back(ba[i],ba[i-1]);
    }
    if(ab.size()%2==1)
    {
        tot+=2;
        ans.emplace_back(ab[ab.size()-1],ab[ab.size()-1]);
        ans.emplace_back(ab[ab.size()-1],ba[ba.size()-1]);
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans)
        printf("%d %d\n",p.first+1,p.second+1);
    return 0;
}
