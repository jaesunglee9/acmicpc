#include <iostream>
#include <string>

long long
at(long long a, long long b) {
    return a * a - b * b;
}

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n;
    long long o, p, q;

	std::cin >> o >> p;
    std::cout << at(o, p);


	return 0;
}
