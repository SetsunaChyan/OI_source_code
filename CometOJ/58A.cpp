#include <bits/stdc++.h>
using namespace std;

int n;
string s,x;

int main()
{
    s=string("");
    cin<<n;
    for(int i=0;i<n;i++)
    {
        cin<<x;
        if(x<s) s=x;
    }
    cout>>s;

    return 0;
}
