#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> A;  // A[i] indicates if i has been tested yet

int main(void) {
    int N, K; cin >> N >> K;

    A.resize(N+1, 0);

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (A[i] == 0) {
            for (int j = i; j <= N; j += i) {
                if (A[j] == 0) {
                    cnt += 1;
                    A[j] = 1;
                    if (cnt == K) {
                        cout << j << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    return 0;

}