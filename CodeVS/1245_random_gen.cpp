#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n = 100;

	printf("%d\n", n);
	for (int i = 0; i < n; ++i){
		printf("%d ", rand() % (n * n) * n + i);
	}
	printf("\n");
	for (int i = 0; i < n; ++i){
		printf("%d ", rand() % (n * n) * n + i);
	}

	return 0;
}