#include <iostream>
#include <string>

int fact(int n);

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n;
    long long o, p, q;

	std::string s, t, u;

	std::cin >> l;

	std::cout << fact(l);

}

int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact ( n - 1 );
    }
}
