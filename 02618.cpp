#include <iostream>
#include <vector>

using namespace std;
const int INF = int(1e9 + 7);

int n, w;
vector<vector<int>> a;
vector<vector<pair<int, int>>> memo; // memo[i][j].first is 


void
move(int i) {
	if (i == 0
	


int
main(void) {
	cin >> n;
	cin >> w;
	a.resize(w + 1);
	memo.resize(w + 1, vector<int>(w + 1));
	memo[0][0] = 0;
		    
	for (int i = 1; i <= w; i++) {
		int x, y; cin >> x >> y;
		a[i] = {x, y};
	}

	for (int i = 1; i <= w; i++) {
		move(i);
	}

	
		

		    

	
