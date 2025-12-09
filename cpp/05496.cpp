#include <iostream>
#include <vector>

using namespace std;

int
N;

vector<int>
A;

vector<int>
R;

int
main(void) {
	cin >> N;1
	A.resize(2 * N);
	R.resize(N);

	for (int i = 0; i < 2 * N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> R[i];
	}
	
