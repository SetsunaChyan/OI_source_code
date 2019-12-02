#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i=2;i*i<=59964251;i++)
        if(59964251%i==0) printf("! %d %d",i,59964251/i);
    return 0;
}
