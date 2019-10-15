#include <bits/stdc++.h>
using namespace std;

int a[5],k,t;
char s[1000];

void p(int x)
{
    if(x==0) printf("S\n");
    else if(x==1) printf("M\n");
    else if(x==2) printf("L\n");
    else if(x==3) printf("XL\n");
    else printf("XXL\n");
}

int main()
{
    for(int i=0;i<5;i++)
        scanf("%d",a+i);
    scanf("%d",&k);
    while(k--)
    {
        scanf("%s",s);
        if(s[0]=='S') t=0;
        else if(s[0]=='M') t=1;
        else if(s[0]=='L') t=2;
        else if(s[0]=='X'&&s[1]=='L') t=3;
        else t=4;
        for(int i=0;i<5;i++)
        {
            int d=t+i;
            if(d>=0&&d<5&&a[d])
            {
                a[d]--;
                p(d);
                break;
            }
            d=t-i;
            if(d>=0&&d<5&&a[d])
            {
                a[d]--;
                p(d);
                break;
            }
        }
    }
    return 0;
}

