#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n,x[10005],ansx=-999;
int  sum=0;
string ans,s[10005];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>x[i];
        sum+=x[i];
    }
    sum/=n;
    sum/=2;
    for(int i=0;i<n;i++)
        if(fabs(x[i]-sum)<fabs(ansx-sum)||fabs(x[i]-sum)==fabs(ansx-sum)&&ans>s[i])
        {
            ans=s[i];
            ansx=x[i];
        }
    int ansx=sum;
    cout<<ansx<<" "<<ans;
    return 0;
}