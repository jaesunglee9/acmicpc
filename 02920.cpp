#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;

    char carr[31];
    int digits[10] = {0};

    int notes[8];
	for (i=0;i<8;i++) {
        std::cin >> notes[i];
    }

    bool ascending = true;
    for (i=0;i<8;i++) {
        if (notes[i] != i + 1) {
            ascending = false;
            break;
        }
    }
    if (ascending == true) {
        std::cout << "ascending";
        return 0;
    }

    bool descending = true;
    for (i=0;i<8;i++) {
        if (notes[i] != 8 - i) {
            descending = false;
            break;
        }
    }
    if (descending == true) {
        std::cout << "descending";
        return 0;
    }

    std::cout << "mixed";

	return 0;
}
