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

    std::cin >> s;

    n = s.length();

    for (auto &ch:s) {
        if (ch >= 'A' && ch <= 'Z') { // is uppercase
            ch += 'a' - 'A';
        } else {
            ch -= 'a' - 'A';
        }
    }

    std::cout << s;



}
