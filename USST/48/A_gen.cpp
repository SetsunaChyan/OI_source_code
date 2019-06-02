#include <bits/stdc++.h>
using namespace std;

char des[100];

void gen()
{
    printf("200\n");
    for(int i=0;i<200;i++)
        printf("%d\n",i);
}

int main()
{
    srand(time(NULL));
    for(int i=1;i<=1;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen();
        fclose(stdout);
    }
    return 0;
}