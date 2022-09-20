#include <iostream>
#include <cstdlib>

int	extended_euclid(int a, int b, int *x, int *y)
{
	int	x1;
	int	y1;
	int	gcd;

	if (!a)
	{
		*x = 0;
		*y = 1;
		return (b);
	}
	gcd = extended_euclid(b % a, a, &x1, &y1);
	*x = y1 - x1 * b / a;
	*y = x1;
	return gcd;
}

int	main(int argc, char **argv)
{
	int	*ints;
	int	x;
	int	y;

	ints = new int[3];
	for (char i = 0; i < 2; ++i)
	{
		ints[i] = atoi(argv[i + 1]);
	}
	printf("gcd:\t%d\n", extended_euclid(ints[0], ints[1], &x, &y));
	printf("x:\t%d\ny:\t%d\n", x, y);
	delete[] ints;
}

