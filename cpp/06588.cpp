#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> is_prime;
vector<int> primes;

void
find_primes() {
    is_prime.resize(1000001, 1);

    for (int i = 2; i <= 1000000; i++) {
        if (is_prime[i] == 1) {
            primes.push_back(i);
            for (int j = i + i; j <= 1000000; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

void
find_pair(int n, int& a, int& b) {
    for (int i = 0; i < primes.size(); i++) {
        int cand = n - primes[i];
        if (cand <= 1000000 && cand > 2 && is_prime[cand] == 1) {
            a = primes[i];
            b = cand;
            return;
        }
    }
}


int
main(void) {
    ios::sync_with_stdio(0);cin.tie(0);

    find_primes();

    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        int a, b;
        find_pair(n, a, b);
        cout << n << " = " << a << " + " << b << '\n'; 
    }

    return 0;
}