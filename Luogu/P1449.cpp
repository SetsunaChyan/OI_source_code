#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

stack<int> st;
char s[1001];
int len;

int main()
{
	scanf("%s", s);
	len = strlen(s);
	int opt = 0;
	for(int i = 0; i < len; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			opt *= 10;
			opt += s[i] - '0';
		}
		else if(s[i] == '.')
		{
			st.push(opt);
			opt = 0;
		}
		else if(s[i] == '@') break;
		else
		{
			int opt2 = st.top();
			st.pop();
			int opt1 = st.top();
			st.pop();
			if(s[i] == '+') st.push(opt1 + opt2);
			else if(s[i] == '-') st.push(opt1 - opt2);
			else if(s[i] == '*') st.push(opt1 * opt2);
			else if(s[i] == '/') st.push(opt1 / opt2);
		}
	}
	printf("%d\n", st.top());
	return 0;
}
