#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int ct[9][4]={{2,4,10,10},
            {1,3,5,10},
            {2,6,10,10},
            {1,5,7,10},
            {2,4,6,8},
            {3,5,9,10},
            {4,8,10,10},
            {5,7,9,10},
            {6,8,10,10}};
int tot=0;
string gg[10000];

int main()
{
    int tot=0;
    for(int i=0;i<(1<<9);i++)
    {
        int k=i,p=9;
        string s="000000000",q="000000000";
        while(k)
        {
            p--;
            if(k&1)
            {
                q[p]='1';
                for(int j=0;j<4;j++)
                    if(ct[p][j]!=10)
                        s[ct[p][j]-1]='1'-s[ct[p][j]-1]+'0';
            }
            k>>=1;
        }
        int g=0;
        for(int j=0;j<9;j++)
            if(s[j]=='1') g++;
        if(g==4) gg[tot++]=q;
    }
    sort(gg,gg+tot);
    for(int i=0;i<tot;i++)
        cout<<gg[i]<<endl;
    return 0;
}