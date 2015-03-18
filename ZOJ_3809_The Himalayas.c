#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int i, j, count, size;
	int a, b, c;
	int number;
	int status;
	scanf("%d", &count);

	for (i = 0; i < count; ++i)
	{
		number = 0;
		status = 0;
		scanf("%d", &size);
		if (size >= 3)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (a < b && b > c) ++number;
		}
		if (size == 2)
		{
			scanf("%d %d", &a, &b);
		}
		if (size == 1)
		{
			scanf("%d", &a);
		}
		for (j = 0; j < size - 3; ++j)
		{
			switch(++status) {
				case 1:
					scanf("%d", &a);
					if (a < c && c > b) ++number;
					break;
				case 2:
					scanf("%d", &b);
					if (b < a && a > c) ++number;
					break;
				case 3:
					scanf("%d", &c);
					if (a < b && b > c) ++number;
					status = 0;
					break;
				default:
					break;
			}
		}
		printf("%d", number);
		if (i != count - 1) printf("\n");
	}
	return 0;
}