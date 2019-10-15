#include <bits/stdc++.h>
using namespace std;

string s;
int four,seven;

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='4') four++;
        else if(s[i]=='7') seven++;
    if(four==0&&seven==0) return printf("-1"),0;
    if(four>=seven) printf("4"); else printf("7");
    return 0;
}
