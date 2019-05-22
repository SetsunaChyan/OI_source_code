#include <bits/stdc++.h>
using namespace std;

int dep[200005],n,now,ans=0;
char s[200005];
stack<int> st;

int main()
{
    scanf("%d%s",&n,s);
    now=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==')')
        {
            dep[st.top()]=dep[i]=now--;
            st.pop();
        }
        else
        {
            st.push(i);
            now++;
        }
    }
    for(int i=0;i<n;i++) ans=max(ans,dep[i]);
    ans/=2;
    for(int i=0;i<n;i++) if(dep[i]<=ans) printf("1"); else printf("0");
    return 0;
}