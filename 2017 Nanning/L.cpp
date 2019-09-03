#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i=1;i<=10000;i++)
    {
        int k=sqrt(1+8*i*i+8*i);
        if(k*k==1+8*i*i+8*i) printf("%d\n",i);
    }
    return 0;
}
