#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int 
N;

vector<int>
A;

vector<vector<int>>
DP;

int
solve(int l, int r, int isTurn) {
	if (l == r) {
		if (isTurn) DP[l][r] = A[l];
		else DP[l][r] = 0;

		return DP[l][r];
	}

	if (isTurn) {
		if (DP[l][r] != -1) {
			return DP[l][r];
		}
		else {
			DP[l][r] = max(solve(l+1, r, 0) + A[l], solve(l, r-1, 0) + A[r]);
			return DP[l][r];
		}
	}
	else {   
		return min(solve(l+1, r, 1), solve(l, r-1, 1));
	}
}

int
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> N;
		A.resize(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		DP.assign(N, vector<int>(N, -1));
		cout << solve(0, N-1, N) << '\n';
	}

	return 0;
}


// better solution
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int dp[n+1],sum[n+1]; sum[0]=0;
        for (int i=1; i<=n; i++){
            cin >> dp[i];
            sum[i]=sum[i-1]+dp[i];
        }
        for (int i=2; i<=n; i++){ //현재 길이
            for (int j=1; j<=n-i+1; j++){ //dp idx
                int s=sum[i+j-1]-sum[j-1]; //j+1 ~ i+j, 길이: i
                dp[j]=s-min(dp[j],dp[j+1]);
            }
        }
        cout << dp[1] << '\n';
    }
    return 0;
}
