#include <bits/stdc++.h>
using namespace std;

int y;

bool check(int x)
{
    int cnt[10];
    memset(cnt,0,sizeof(cnt));
    while(x)
    {
        cnt[x%10]++;
        x/=10;
    }
    for(int i=0;i<10;i++) if(cnt[i]>1) return false;
    return true;
}

int main()
{
    scanf("%d",&y);
    while(y)
    {
        y++;
        if(check(y))
        {
            printf("%d",y);
            return 0;
        }
    }
    return 0;
}
