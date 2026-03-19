#include <iostream>
#include <vector>

using namespace std;
const int inf = 1e9 + 7;

int
N;

// DP[i] is gcd of all A except A[i]
// DPL[i] is gcd of A until i
vector<int>
A, DPL, DPR;

int
gcd(int a, int b) {	
	if (b > a) return gcd(b, a);

	int r;
	r = a % b;

	if (r == 0) {
		return b;
	}

	return gcd(b, r);
}			


int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> N;
	
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
		
	DPL.resize(N);
	DPL[0] = A[0];
	for (int i = 1; i < N; i++) {
		DPL[i] = gcd(DPL[i - 1], A[i]);
	}
	
	
	DPR.resize(N);
	DPR[N-1] = A[N-1];
	for (int i = N - 2; i >= 0; i--) {
		DPR[i] = gcd(DPR[i + 1], A[i]);
	}

	int
	maxgcd, maxk;
	maxgcd = 0;
	
	for (int i = 1; i < N - 1; i++) {
		int
		num;
		
		num = gcd(DPL[i-1], DPR[i + 1]);
		if (num > maxgcd && A[i] % num != 0) {
			maxgcd = num;
			maxk = A[i];
		}
	}

	int
	num;

	// if A[0] was removed
	num = DPR[1];
	if (num > maxgcd && A[0] % num != 0) {
		maxgcd = num;
		maxk = A[0];
	}

	// if A[N-1] was removed
	num = DPL[N-2];
	if (num > maxgcd && A[N-1] % num != 0) {
		maxgcd = num;
		maxk = A[N-1];
	}

	if (maxgcd == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << maxgcd << ' ' << maxk << '\n';
	}

	return 0;
}

	
	

	

	
	
	
