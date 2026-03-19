#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;
    bool w, x, y, z;

    std::string line;
    i = 1;
    while (true) {
        std::getline(std::cin, line);
        if (line[0] == '0') {
            break;
        }
        std::cout << "Case " << i << ": Sorting... done!" << '\n';
        i++;
    }
}
