#include <cstdio>
#include <cstring>
#include <algorithm>

char s[20][20], temp[20];
int n;

bool substring(char a[20], char b[20])
{
    if(strlen(a) < strlen(b)) return false;
    for(int i = 0; i < strlen(b); i++)
        if(a[i] != b[i]) return false;
    return true;
}

bool cmp(char a[20], char b[20])
{
    if(strlen(a) == strlen(b))
        return strcmp(a, b) > 0;
    if(substring(a, b))
    {
        return a[strlen(b)] > b[0];
    }
    else if(substring(b, a))
    {
        return b[strlen(a)] < a[0];
    }
    return strcmp(a, b) > 0;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%s", s[i]);
    //std::sort(s,s+n,cmp);
    for(int i = 0; i < n - 1; i++)
        for(int j = n - 1; j > i; j--)
        {
            if(cmp(s[j], s[j - 1]))
            {
                strcpy(temp, s[j]);
                strcpy(s[j], s[j - 1]);
                strcpy(s[j - 1], temp);
            }
        }
    for(int i = 0; i < n; i++) printf("%s", s[i]);
    return 0;
}
