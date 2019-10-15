#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
struct SEG
{
    int seg[MAXN<<2],ortag[MAXN<<2],andtag[MAXN<<2],xortag[MAXN<<2];

}T[20];

int main()
{
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        printf("%d\n",(a|b)^c);
        printf("%d\n",(a^c)|b);
    }
    return 0;
}
