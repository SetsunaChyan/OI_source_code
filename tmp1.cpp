#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tot=0;
    for(int i=0;i<=500;i++)
        for(int j=0;j<=500;j++)
            if(j>=i&&j*2+i==500) tot++;
    printf("%d",tot);
    return 0;
}
