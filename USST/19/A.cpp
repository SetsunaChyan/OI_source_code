#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline bool cmp(string a,string b)
{
    return a+b>b+a;
}

int main()
{
    int n,flag=1;
    string s[20];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        if(s[i]!="0") flag=0;
    }
    if(flag)
    {
        cout<<"0";
        return 0;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
        cout<<s[i];
    return 0;
}
