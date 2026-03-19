#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h, w,x;
	int i, j, k, l, m, n;
    long long o, p, q;

	std::string s, t, u;



    f = 0;  // sum of weighted scores
    w = 0;  // sum of credits
    for (i=0;i<20;i++) {
        std::cin >> s >> g >> u;
        if (u == "P") {
            continue;
        } else {
            if (u == "A+") {
                h = 4.5;
            } else if (u == "A0") {
                h = 4.0;
            } else if (u == "B+") {
                h = 3.5;
            } else if (u == "B0") {
                h = 3.0;
            } else if (u == "C+") {
                h = 2.5;
            } else if (u == "C0") {
                h = 2.0;
            } else if (u == "D+") {
                h = 1.5;
            } else if (u == "D0") {
                h = 1.0;
            } else if (u == "F") {
                h = 0;
            }
        }

        f += g * h;
        w += g;
    }

    std::cout << f / w;


}
