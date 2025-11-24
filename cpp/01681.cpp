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

	std::cin >> n >> o;

    i = 0;
    j = 0;
    while (i < n) {
        j++;
        p = j;
        bool usable = true;
        do {
            if (p % 10 == o) {
                usable = false;
                break;
            }
            p = p / 10;
        } while (p > 0);
        if (usable) {
            i++;
        }
    }
    std::cout << j;

	return 0;
}
