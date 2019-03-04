#include <iostream>
#include <string>

using namespace std;

string mid,suf;

void build(string mid,string suf)
{
    if(mid.size())
    {
        char ch=suf[suf.size()-1];
        cout<<ch;
        int i=mid.find(ch);
        build(mid.substr(0,i),suf.substr(0,i));
        build(mid.substr(i+1),suf.substr(i,suf.size()-i-1));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>mid>>suf;
    build(mid,suf);
    return 0;
}