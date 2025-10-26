#include <iostream>
#include <vector>

using namespace std;

int
main(void) {
    int
    n;

    vector<int>
    p, v;  // primes, visited

    cin >> n;

    v.resize(n+1, 0);
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            p.push_back(i);
            for (int j = i; j <= n; j += i) {
                v[j] = 1;
            }
        }
    }

    int i = 0;
    while (n > 1 && i < p.size()) {
        if (n % p[i] == 0) {
            cout << p[i] << '\n';
            n /= p[i];
        }
        else {
            i++;
        }
    }
}