#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k;
    long long l, m, n;

	std::string s, t, u;

	std::cin >> l >> m;

    n = l - m;
    if (n < 0) {
        n = -1 * n;
    }

    std::cout << n;


	return 0;
}
