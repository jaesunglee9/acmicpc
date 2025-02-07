#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;

    std::cin >> m;
    std::cin.ignore();
    for(i=0;i<m;i++){
        std::string line;
        std::getline(std::cin, line);
        p = 0;
        n = 0;
        for (char a : line) {
            if (a == 'O') {
                n += 1;
                p += n;
            } else {
                n = 0;
            }
        }
        std::cout << p << '\n';
    }

	return 0;
}
