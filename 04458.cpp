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

	std::cin >> n;
    std::cin.ignore();

    std::string line;
    for (i=0;i<n;i++) {
        std::getline(std::cin, line);
        if (97 <= line[0] && line[0] <= 122) {
            line[0] -= 32;
        }

        std::cout << line << '\n';
    }

	return 0;
}
