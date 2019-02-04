#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n,z[10],ans=0;

void test(int add,int divs)
{
    int a=0,b=0,c=0;
    for(int i=0;i<add;i++)
    {
        a*=10;
        a+=z[i];
    }
    for(int i=add;i<divs;i++)
    {
        b*=10;
        b+=z[i];
    }
    for(int i=divs;i<9;i++)
    {
        c*=10;
        c+=z[i];
    }
    if(a+b/c==n&&b%c==0) ans++;
}

int main()
{
    for(int i=0;i<10;i++) z[i]=i+1;
    scanf("%d",&n);
    int l=log10(n)+1;
    do
    {
        for(int i=1;i<=l;i++)
            for(int j=i+1;j<9;j++)
                test(i,j);
    }while(next_permutation(z,z+9));
    printf("%d",ans);
    return 0;
}