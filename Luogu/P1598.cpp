#include <iostream>
#include <string.h>

using namespace std;

string s[4];
char gra[255][26];
int zm[26],maxn=0;

int main()
{
	int i,j;
	char k;
	for(i=0;i<26;i++)
		zm[i]=0;
	for(i=0;i<255;i++)
		for(j=0;j<26;j++)
			gra[i][j]=' ';
	for(i=0;i<4;i++) 
		getline(cin,s[i]);
	for(i=0;i<4;i++)
		for(j=0;j<s[i].length();j++)
			if(s[i][j]>='A'&&s[i][j]<='Z')
				zm[s[i][j]-'A']++;
	for(i=0;i<26;i++)
	{
		for(j=0;j<zm[i];j++)
			gra[j][i]='*';
		if(zm[i]>maxn) maxn=zm[i];
	}
	for(i=maxn-1;i>=0;i--) 
	{
		for(j=0;j<25;j++)
			cout<<gra[i][j]<<' ';
		cout<<gra[i][25]<<endl;
	}
	for(k='A';k<='Y';k++) cout<<k<<' ';
	cout<<'Z';
	return 0;
}
