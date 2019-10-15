#include <bits/stdc++.h>
using namespace std;

int n,cnt,x[205],y[205];

bool up(int a)
{
    for(int i=0;i<n;i++)
        if(x[i]==x[a]&&y[i]<y[a]) return true;
    return false;
}

bool low(int a)
{
    for(int i=0;i<n;i++)
        if(x[i]==x[a]&&y[i]>y[a]) return true;
    return false;
}

bool left(int a)
{
    for(int i=0;i<n;i++)
        if(x[i]<x[a]&&y[i]==y[a]) return true;
    return false;
}

bool right(int a)
{
    for(int i=0;i<n;i++)
        if(x[i]>x[a]&&y[i]==y[a]) return true;
    return false;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",x+i,y+i);
    for(int i=0;i<n;i++)
        if(up(i)&&low(i)&&left(i)&&right(i)) cnt++;
    printf("%d",cnt);
    return 0;
}
