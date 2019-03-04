#include <iostream>
#include <string>
#include <memory.h>
#include <cstdio>

using namespace std;

const int ten[4]={1,10,100,1000};
const int maxl=1000;

int max(const int &a,const int &b)
{
    return a>b?a:b;
}

struct BigNumber
{
    int d[maxl];
    BigNumber(string s)
    {
        int len=s.size();
        d[0]=(len-1)/4+1;
        int i,j,k;
        for(i=1;i<maxl;i++)d[i]=0;
        for(i=len-1;i>=0;i--)
        {
            j=(len-i-1)/4+1;
            k=(len-i-1)%4;
            d[j]+=ten[k]*(s[i]-'0');
        }
        while(d[0]>1&&d[d[0]]==0)d[0]--;
    }
    BigNumber(){*this=BigNumber(string("0"));}
    string toString()
    {
        string s("");
        int i,j,temp;
        for(i=3;i>=1;i--)if(d[d[0]]>=ten[i]) break;
        temp=d[d[0]];
        for(j=i;j>=0;j--)
        {
            s=s+(char)(temp/ten[j]+'0');
            temp%=ten[j];
        }
        for(i=d[0]-1;i>0;i--)
        {
            temp=d[i];
            for(j=3;j>=0;j--)
            {
                s=s+(char)(temp/ten[j]+'0');
                temp%=ten[j];
            }
        }
        return s;
    }
};


BigNumber operator + (const BigNumber &a,const BigNumber &b)
{
    BigNumber c;
    c.d[0]=max(a.d[0],b.d[0]);
    int i,x=0;
    for(i=1;i<=c.d[0];i++)
    {
        x=a.d[i]+b.d[i]+x;
        c.d[i]=x%10000;
        x/=10000;
    }
    while(x!=0)
    {
        c.d[++c.d[0]]=x%10000;
        x/=10000;
    }
    return c;
}

int main()
{
    string a,b;
    cin>>a>>b;
    BigNumber x(a),y(b),z=x+y;
    cout<<z.toString()<<endl;
    return 0;
}
