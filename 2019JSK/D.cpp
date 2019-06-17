#include <bits/stdc++.h>
using namespace std;

char s[5000005];
int l,k;
deque<int> q;

int main()
{
    scanf("%s%d",s,&k);
    l=strlen(s);
    for(int i=0;i<l;i++)
    {
        while(!q.empty()&&q.size()+l-i>k&&s[i]<s[q.back()]) q.pop_back();
        q.push_back(i);
    }
    for(int i=0;i<k;i++)
    {
        printf("%c",s[q.front()]);
        q.pop_front();
    }
    return 0;
}
