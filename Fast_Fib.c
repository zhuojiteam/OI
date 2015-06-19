#include <stdio.h>



int fib(int n) {
	if (n < 3) return 1;
	else {
		int next = n / 2;
		int a = fib(next); int b = fib(next + 1);
		switch (n % 2) {
		case 0:
			return a * (2 * b - a);
		case 1:
			return a * a + b * b;
		}
	}

}

int main(int argc, char const *argv[])
{
	
	for (int i = 1; i < 100; ++i)
	{
		printf("%d\n", fib(i));
	}

	return 0;
}