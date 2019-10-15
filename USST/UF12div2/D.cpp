#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k,sum;
vector<int> ans;

int main()
{
    scanf("%lld",&k);
    for(int i=0;i<26;i++)
        for(int j=0;sum+j<=k;j++)
            sum+=j,ans.push_back(i);
    for(auto a:ans) printf("%c",a+'a');
    return 0;
}
