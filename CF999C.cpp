#include <bits/stdc++.h>
using namespace std;

string s;
int n,k;

int main()
{
    cin>>n>>k>>s;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<s.size();j++)
            if(s[j]=='a'+i)
            {
                s[j]='0';
                k--;
                if(!k) break;
            }
        if(!k) break;
    }
    for(int i=0;i<s.size();i++)
        if(s[i]!='0') cout<<s[i];
    return 0;
}
