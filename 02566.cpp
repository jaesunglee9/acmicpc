#include <iostream>
#include <string>
#include <iomanip>

int main() {
    char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n;
    long long o, p, q;

	std::string s, t, u;

    n = 0;
    m = 0;
    l = 0;
    for (i = 0; i < 9; ++i) {
        for (j= 0 ; j < 9; ++j) {
            int temp;
            std::cin >> temp;
            if (temp > n) {
                n = temp;
                m = i;
                l = j;
            }
        }
    }

    std::cout << n << '\n';
    std::cout << m+1 << ' ' << l+1 << '\n';
}
