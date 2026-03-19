#include <iostream>
#include <string>


int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n;
    long long o, p, q;

	std::string s, t, u;

    std::cin >> n;

    l = 0;
    while (1) {
        if ( n <= (1 + 3 * (l) * (l+1))) {
            std::cout << l+1;
            break;
        }
        l++;
    }
    return 0;
}
