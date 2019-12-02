#include <bits/stdc++.h>
using namespace std;

int a,b,c1,c2,c3;

int main()
{
    scanf("%d%d",&a,&b);
    for(int x=1;x<=6;x++)
    {
        if(abs(a-x)<abs(b-x)) c1++;
        else if(abs(a-x)==abs(b-x)) c2++;
        else c3++;
    }
    printf("%d %d %d",c1,c2,c3);
    return 0;
}
