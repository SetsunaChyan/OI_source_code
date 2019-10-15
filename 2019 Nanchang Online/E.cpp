#include<bits/stdc++.h>

using namespace std;

int main()

{

int n,i=0,m,p;

scanf("%d%d",&n,&m);//n总人数，m步长

n--;

cout<<1<<endl;

while(++i<=n)

{

p=i*m;

while(p>n)

p=p-n+(p-n-1)/(m-1);

printf("%d\n",p+1);

}

return 0;

}
