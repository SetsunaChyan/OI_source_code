#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
int main()
{
    int _;
    cin>>_;
    while(_--)
    {
        cin>>n>>m>>k;
        cout<<min((m+1)*k,m+1+(k-1)*(m/(n-k+1)+1))<<endl;
    }
    return 0;
}
