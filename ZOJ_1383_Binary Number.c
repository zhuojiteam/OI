#include <stdio.h>

int main(int argc, char *argv[])
{
	int times, j;
	scanf("%d", &times);
	int input;
	int i;
	for (j = 0; j < times; ++j)
	{
		i = 0;
			scanf("%d", &input);
			while (input != 0)
			{
				if (input % 2 == 1)
				{
					printf("%d", i);
					if (input != 1)
					{
						printf(" ");
					}
				}
				
				++i;
				input = input >> 1;
			}
			if (j < times - 1)
			{
				
				printf("\n");
			}
	}
	

	return 0;
}
