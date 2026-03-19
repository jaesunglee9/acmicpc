#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

void mult(std::vector<int>& res, int x) {
    int carry = 0;
    for (size_t i = 0; i < res.size(); i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }
}

void fact(int n) {
    std::vector<int> res = {1};
    for (int i = 2; i <= n; i++) {
        mult(res, i);
    }

    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        std::cout << *it;
    }

    std::cout << std::endl;
}

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;
    bool w, x, y, z;

    std::cin >> l;
    if (l == 0) {
        std::cout << '1';
        return 0;
    }

    fact(l);



    return 0;
}
