#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r;
    long long t, u, v;

    char carr[31];

	std::cin >> f >> g;
    h = f / g / g;

    if (h > 25.0) {
        std::cout << "Overweight";
    } else if (h >= 18.5) {
        std::cout << "Normal weight";
    } else {
        std::cout << "Underweight";
    }
}
