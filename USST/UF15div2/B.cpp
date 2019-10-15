#include <bits/stdc++.h>
using namespace std;

char s[2000];
int n,dol,cent;

int main()
{
    scanf("%s",s);
    n=strlen(s);
    int nowd=0,dot=0;
    for(int i=0;i<=n;i++)
    {
        if(i==n||s[i]>='a'&&s[i]<='z')
        {
            if(dot!=2)
                dol+=nowd;
            else
                dol+=nowd/100,cent+=nowd%100;
            nowd=0,dot=0;
            continue;
        }
        if(s[i]=='.')
        {
            dot=0;
            continue;
        }
        nowd*=10;
        nowd+=s[i]-'0';
        dot++;
    }
    dol+=cent/100;
    cent%=100;
    char fuck[100];int cur=0,cnt=0;
    if(dol==0)
    {
        printf("0");
        if(cent) printf(".%02d",cent);
        return 0;
    }
    memset(s,0,sizeof(s));
    while(dol)
    {
        if(cnt&&cnt%3==0) fuck[cur++]='.';
        fuck[cur++]=dol%10+'0';
        dol/=10;
        cnt++;
    }
    for(int i=cur-1;i>=0;i--)
        printf("%c",fuck[i]);
    if(cent) printf(".%02d",cent);
    return 0;
}
