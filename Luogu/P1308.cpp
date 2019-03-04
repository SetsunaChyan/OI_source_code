#include <iostream>

using namespace std;

string art,word;

int main()
{
	int i,j,first,ans=0;
	getline(cin,word);
	getline(cin,art);
	int l1=art.size(),l2=word.size();
	for(i=0;i<l1;i++) if(art[i]<='Z') art[i]+=32;
	for(i=0;i<l2;i++) if(word[i]<='Z') word[i]+=32;
	i=0; 
	while(i<l1)
	{
		for(j=0;j<l2;j++)
			if(art[i+j]!=word[j]) break;
		if(j==l2&&(art[i+j]>'z'||art[i+j]<'a'))
		{
			if(ans==0) first=i;
			ans++;
		}
		while(i<l1&&(art[i]>='a'&&art[i]<='z')) i++;
		i++; 
	}
	if(ans)
		cout<<ans<<" "<<first<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}
