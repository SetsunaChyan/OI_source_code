#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll opt,x;
vector<ll> a;
int main(int argc, char * argv[])
{
    setName("warmup_d_checker");
    registerTestlibCmd(argc, argv);
    if(!ouf.seekEof()) opt=ouf.readLong();
    else quitf(_wa,"No output");
    if(opt!=1&&opt!=2) quitf(_wa,"Wrong Task");
    while(!ouf.seekEof())
        x=ouf.readLong(),a.push_back(x);
    if(opt==1)
        if(a.size()!=4) quitf(_wa,"Wrong Answer on Task A");
        else if(a[0]==1&&a[1]==1&&a[2]==0&&a[3]==0) quitf(_ok,"Task A Accepted");
        else quitf(_wa,"Wrong Answer on Task A");
    else if(opt==2)
        if(a.size()!=5) quitf(_wa,"Wrong Answer on Task B");
        else if(a[0]==2&&a[1]==3&&a[2]==1&&a[3]==4&&a[4]==5) quitf(_ok,"Task B Accepted");
        else quitf(_wa,"Wrong Answer on Task B");
    quitf(_wa,"Unknown Error");
}
