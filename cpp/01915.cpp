
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> TABLE;
vector<vector<int>> DP;
int best = 0;


void
fill_dp() {
    for (int i = 0; i < N; i++) {
        DP[i][0] = TABLE[i][0];
    }

    for (int j = 0; j < M; j++) {
        DP[0][j] = TABLE[0][j];
    }



    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (TABLE[i][j] == 0) {
                DP[i][j] = 0;
            }
            else {
                int tmp = DP[i-1][j-1];
                if (DP[i-1][j] < tmp) tmp = DP[i-1][j];
                if (DP[i][j-1] < tmp) tmp = DP[i][j-1];

                DP[i][j] = tmp + 1;

                best = max(best, DP[i][j]);
            }
        }
    }
}


int
main(void) {
    ios::sync_with_stdio(0);

    cin >> N >> M;
    TABLE.resize(N, vector<int>(M));
    DP.resize(N, vector<int>(M, 0));


    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        for (int j = 0; j < M; j++) {
            TABLE[i][j] = str[j] - '0';
        }
    }

    int one = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (TABLE[i][j] == 1) {
                one = 1;
                best = 1;
                break;
            }
        }
        if (one == 1) {
            break;
        }
    }

    fill_dp();
    

    cout << best * best << '\n';
    return 0;
}