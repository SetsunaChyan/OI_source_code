#include <bits/stdc++.h>
using namespace std;

int n;
char s[2000][2000];

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
            putchar(s[i][j]);
        puts("");
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    s[0][0]=s[0][1]=s[1][1]='C';
    s[1][0]='P';
    for(int i=2;i<=10;i++)
    {
        int k=1<<(i-1);
        for(int x=k;x<2*k;x++)
            for(int y=k;y<2*k;y++)
            {
                s[x][y]=s[x-k][y]=s[x-k][y-k];
                if(s[x-k][y-k]=='C') s[x][y-k]='P';
                else s[x][y-k]='C';
            }
    }

    while(_--) solve();

    return 0;
}
