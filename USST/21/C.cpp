#include <iostream>
#include <map>
#include <string>

using namespace std;

int n,m=-1;
map<string,int> mp;
string s;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    cin>>n;
    mp.clear();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(mp.find(s)!=mp.end())
            mp[s]++;
        else
            mp[s]=1;
        m=max(m,mp[s]);
    }
    if(m>n/2)//n-m+2<=m  m>=(n+2)/2  m>=n/2+1 m>n/2
        cout<<2*(n-m)+1;
    else
        cout<<n;
    return 0;
}