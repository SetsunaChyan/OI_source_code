#include <iostream>
#include <map>
#include <string>

using namespace std;

int n;
string s;
map<string,bool> p;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        p[s]=true;
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        map<string,bool>::iterator it=p.find(s);
        if(it!=p.end())
        {
            if((*it).second==true)
            {
                (*it).second=false;
                cout<<"OK"<<endl;
            }
            else
                cout<<"REPEAT"<<endl;
        }
        else
            cout<<"WRONG"<<endl;
    }
    return 0;
}
