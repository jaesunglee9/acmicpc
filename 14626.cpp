#include <iostream>
#include <string>
#include <vector>

using namespace std;

int
main(void) {
    string str;
    cin >> str;
    vector<int> isbn(13, 0);
    int digit, coeff;

    for (int i = 0; i < 13; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            isbn[i] = str[i] - '0';
        }
        else {
            digit = i;
            if (i % 2 == 0) {
                coeff = 1;
            }
            else {
                coeff = 3;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 13; i++) {
        if (i % 2 == 0) {
            sum += isbn[i];
        }
        else {
            sum += isbn[i] * 3;
        }
    }

    int res = 0;
    for (int i = 0; i < 10; i++) {
        if ((sum + coeff * i) % 10 == 0) {
            res = i;
            break;
        }
    }   

    cout << res << '\n';

    return 0;


}