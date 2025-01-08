#include <unistd.h>
#include <stdio.h>
int main()
{
	int pfd[2];
	pipe(pfd);
	printf("%d\n", pfd[0]);
	printf("%d\n", pfd[1]);

	return 0;
}
