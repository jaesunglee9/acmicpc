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

    a = s[0];
    if (a == 'F') {
        f = .0;
    } else {
        switch (a) {
            case 'A':
                f = 4.0;
                break;
            case 'B':
                f = 3.0;
                break;
            case 'C':
                f = 2.0;
                break;
            case 'D':
                f = 1.0;
                break;
        }
        b = s[1];
        switch (b) {
            case '+':
                f += .3;
                break;
            case '0':
                f += .0;
                break;
            case '-':
                f -= .3;
                break;
        }
    }

    printf("%.1f", f);



}
