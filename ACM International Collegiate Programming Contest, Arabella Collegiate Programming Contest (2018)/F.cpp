#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[30]={0};
ll ansx=0;
ll ansy=0;
ll MINcnty=0;
ll ansarr[40]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};

void gaox()
{
    MINcnty=INT_MAX;
    ll cnt=0;

    for(int i=0;i<26;i++)
    {
        if(arr[i]>2)
        {
            cnt+=2;
            MINcnty=min(MINcnty,arr[i]/2);
        }
    }
    int flag=1;
    ll tmpcnt=0;
    for(int i=0;i<26;i++)
    {
        if(arr[i]>0)
        {
            if(arr[i]%2==1)
            {
                tmpcnt+=arr[i];
            }
            else
            {
                tmpcnt+=arr[i]-2*MINcnty;
            }
        }
    }
    if(tmpcnt>0)
    {
        cnt++;
        MINcnty = min(MINcnty,tmpcnt);
    }
    ansx=cnt;
}

ll gaoy()
{

    int cnt=ansx/2;
    /*
    ll ans=1;
    for(int i=1;i<=cnt;i++)
    {
        ans*=i;
    }
    */
    cout<<cnt<<endl;
    return ansarr[cnt];
}

int main()
{
    int _t;
    scanf("%d",&_t);
    while(_t--)
    {
        for(int i=0;i<26;i++)
        {
            scanf("%lld",arr+i);
        }
        gaox();
        printf("%lld %lld\n",ansx,min(ansarr[ansx/2],MINcnty));
    }
    return 0;
}
/*
1
20 20 20 20 20 1 1 26 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20
*/
