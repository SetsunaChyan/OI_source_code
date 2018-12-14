#include <cstdio>

int main()
{
	char str[16][13]={{"DDDDULULULUL"},
				  {"DDDDURURURUR"},
				  {"DDDDRLRLRLRL"},
				  {"DDDDRURURURU"},
				  {"UUUUDLDLDLDL"},
				  {"UUUULDLDLDLD"},
				  {"UUUURDRDRDRD"},
				  {"UUUUDRDRDRDR"},
				  {"RRRRLDLDLDLD"},
				  {"RRRRDLDLDLDL"},
				  {"RRRRULULULUL"},
				  {"RRRRLULULULU"},
				  {"LLLLRDRDRDRD"},
				  {"LLLLDRDRDRDR"},
				  {"LLLLRURURURU"},
				  {"LLLLURURURUR"}};
	int n;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<16;i++)
			printf("%s",str[i]);
		printf("\n");
	}
	return 0;				  
}