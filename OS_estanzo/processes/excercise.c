#include <stdio.h>
#include <unistd.h>

int main() {
	int count = 10;
	while(count >= 0) {
		sleep(1);
		printf("%d\n", count);
		count--;
	}
}
