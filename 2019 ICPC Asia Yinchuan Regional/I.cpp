#include <bits/stdc++.h>
using namespace std;

/*
    2019 ICPC Asia Yinchuan Regional I
    x进制转换成y进制 x,y<=52
*/

int x,y,n;
char s[1000005];
vector<char> t;

inline int get(char x)
{
    if(x>='0'&&x<='9') return x-'0';
    if(x>='A'&&x<='Z') return x-'A'+10;
    return x-'a'+36;
}

inline char gao(int x)
{
    if(x<10) return x+'0';
    if(x<36) return x-10+'A';
    return x-36+'a';
}

int main()
{
    scanf("%d%d%s",&x,&y,s);
    int i=0;n=strlen(s);
    while(i<n)
    {
        int r=0,cur;
        for(int j=i;j<n;j++)
        {
            cur=r*x+get(s[j]);
            s[j]=gao(cur/y);
            r=cur%y;
        }
        t.push_back(gao(r));
        while(s[i]=='0') i++;
    }
    reverse(t.begin(),t.end());
    for(auto c:t) printf("%c",c);
    return 0;
}
