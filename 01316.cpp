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

    std::cin >> n;


    m = 0;  // cnt
    for(i=0;i<n;i++) {
        std::cin >> s;
        l = s.length();
        int alp[26] = {0};
        for (j=0;j<l;j++) {
            if (j == l-1 || s[j] != s[j+1]) {
                if (alp[s[j] - 'a'] != 0) {
                    break;
                }
                alp[s[j]-'a'] += 1;
            }
        }
        if (j == l) m++;
    }

    std::cout << m;



}

