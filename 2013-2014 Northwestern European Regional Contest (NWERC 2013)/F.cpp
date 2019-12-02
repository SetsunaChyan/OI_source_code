#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int u[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int v[14]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int cal(int x)
{
    int t,tt;
    t=x/4-1582/4;
    tt=x/4-x/100+x/400-1582/4+1582/100-1582/400;
    return t-tt+11;
}
int f(int a,int b,int c)
{
    int sum=0;
    if(a%4) {
        for(int i=1;i<b;i++) sum+=u[i];
        sum+=c;
    }
    else {
        for(int i=1;i<b;i++) sum+=v[i];
        sum+=c;
    }
    return sum;
}

int main()
{
    int a,b,c;
    while(~scanf("%d-%d-%d",&a,&b,&c))
    {
        int x,y;
        x=cal(a-1);
        y=f(a,b,c);
        int p=1,q=0;
        for(int i=1;i<=x+y;i++)
        {
            if((a%4==0&&a%100!=0)||a%400==0) {
                if(q==v[p]) {
                    if(p==12) {a++;p=q=1;}
                    else {q=1; p++;}
                }
                else q++;
            }

            else {
                if(q==u[p]) {
                    if(p==12) {
                        a++; p=q=1;
                    }
                    else {q=1; p++;}
                }
                else q++;
            }
            //else c++;
        }
        printf("%d-%02d-%02d\n",a,p,q);
    }
    return 0;
}
