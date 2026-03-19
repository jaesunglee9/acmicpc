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
    while (1) {
        std::getline(std::cin, line);
        if (line == "0") {
            break;
        }

        w = true;
        l = line.length();
        m = l / 2;  // integer division (floor)
        for (i = 0; i < m; i++) {
            if (line[i] != line[l-1-i]) {
                w = false;
            }
        }

        if (w) {
            std::cout << "yes" << '\n';
        } else {
            std::cout << "no" << '\n';
        }
    }
}
