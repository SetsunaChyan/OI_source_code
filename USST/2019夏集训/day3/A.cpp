#include <bits/stdc++.h>
using namespace std;

char op[100005];
stack<int> s;

int main()
{
    scanf("%s",op);
    int l=strlen(op),opt=0;
    for(int i=0;i<l;i++)
    {
        if(op[i]>='0'&&op[i]<='9')
            opt=opt*10+op[i]-'0';
        else if(op[i]=='.')
            s.push(opt),opt=0;
        else if(op[i]=='*')
        {
            int a=s.top();s.pop();
            int b=s.top();s.pop();
            s.push(b*a);
        }
        else if(op[i]=='-')
        {
            int a=s.top();s.pop();
            int b=s.top();s.pop();
            s.push(b-a);
        }
        else if(op[i]=='/')
        {
            int a=s.top();s.pop();
            int b=s.top();s.pop();
            s.push(b/a);
        }
        else if(op[i]=='+')
        {
            int a=s.top();s.pop();
            int b=s.top();s.pop();
            s.push(b+a);
        }
    }
    printf("%d",s.top());
    return 0;
}
