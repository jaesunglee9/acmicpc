// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
int fwr(vector<vector<int>>& b, int sx, int sy) {
	vector<int> wr = {0,1,0,1,0,1,0,1};
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += wr[i] ^ b[sx][sy + i];
	}
	return sum;
}

int fbr(vector<vector<int>>& b, int sx, int sy) {
	vector<int> br = {1,0,1,0,1,0,1,0};
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += br[i] ^ b[sx][sy + i];
	}
	return sum;
}

int fw(vector<vector<int>>& b, int sx, int sy) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += fwr(b, sx+2*i, sy);
		sum += fbr(b, sx+2*i+1, sy);
	}
	return sum;
}

int fb(vector<vector<int>>& b, int sx, int sy) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += fbr(b, sx+2*i, sy);
		sum += fwr(b, sx+2*i+1, sy);
	}
	return sum;
}

int f(vector<vector<int>>& b, int sx, int sy) {
        return min(fw(b, sx, sy), fb(b, sx, sy));
}	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			b[i][j] = int(temp == 'B');
		}
	}

	int tempmin = INF;
	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) {
			tempmin = min(tempmin, f(b, i, j));
		}		
	}
			      
	cout << tempmin << '\n';		      

	return 0;
}


