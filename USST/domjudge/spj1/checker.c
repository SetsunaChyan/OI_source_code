#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *testin, *testout, *progout;

/*
printf出来的东西会重定向到 "${FEEDBACKDIR}/judgemessage.txt" 里，所以只要使用了printf就能得到一个WA
testin指向case.in，testout指向case.out，评测程序的输出直接scanf就行了
*/

void spj()
{
	int tot = 0, l, r, ans;
	fscanf(testin, "%d%d", &l, &r);
	while (~scanf("%d", &ans))
	{
		tot++;
		if (tot > 1)
			break;
	}
	if (tot != 1)
		printf("Too much output.\n");
	if (ans < l || ans > r)
		printf("Wrong Answer.\n");
}

int main(int argc, char **argv)
{
	if (argc - 1 < 2)
	{
		fprintf(stderr, "error: not enough arguments: 2 required\n");
		return 1;
	}
	testin = fopen(argv[1], "r");
	testout = fopen(argv[2], "r");
	progout = stdin;
	if (testin == NULL || progout == NULL || testout == NULL)
	{
		fprintf(stderr, "error: cannot open files\n");
		return 1;
	}

	spj();

	fclose(testin);
	fclose(progout);
    fclose(testout);
    
	return 0;
}