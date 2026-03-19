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

    l = s.length();

    n = 0;  // acc sum of croatian alphabet
    i = 0;
    while (i < l) {
        if (s[i] == 'c') {
            if (s[i+1] == '=') i++;
            if (s[i+1] == '-') i++;
        } else if (s[i] == 'd') {
            if (s[i+1] == 'z' && s[i+2] =='=') i+=2;
            if (s[i+1] == '-') i++;
        } else if (s[i] == 'l' && s[i+1] == 'j') {
            i++;
        } else if (s[i] == 'n' && s[i+1] == 'j') {
            i++;
        } else if (s[i] == 's' && s[i+1] == '=') {
            i++;
        } else if (s[i] == 'z' && s[i+1] == '=') {
            i++;
        }
        n++;
        i++;
    }

    std::cout << n;



}
