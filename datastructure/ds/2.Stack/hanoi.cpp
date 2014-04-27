
#include <stdio.h>
void move(char, int, char);


void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, 1, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

void move(char a, int n, char b)
{
	static int c = 0;
	printf("%i. Move disk %i from %c to %c\n", ++c, n, a, b);
}

