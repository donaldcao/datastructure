#include <stdio.h>

extern void convert();
extern void hanoi(int n, char x, char y, char z);

// Covert decimal number to octal number.
int main()
{
	hanoi(10, 'a', 'b', 'c');

	convert();

	getchar();
	getchar();

	return 0;
}