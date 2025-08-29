#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int INF = 10e9+1;

int n, m;
int min_dist = INF;

vector<vector<int>> city;
int n_home;
vector<pair<int, int>> home; // homes[i] : coord of ith home
int n_chicken;
vector<pair<int, int>> chicken;  // chickens[j] : coord of jth chicken
vector<vector<int>>  dist;  // dist[i][j] : chicken distance of ith home to jth chicken



int
city_dist(vector<int>& chosen) {
  int res=0;
  for (int i = 0; i < n_home; i++) {
    
    

void
dfs(vector<int>& res, int depth, int index) {
  if (depth == m) {
    min_dist = min(min_dist, city_dist(res));
    return;
  }
	
  for (int i = index; i <= n_chicken - (m - depth); ++i) {
		res[depth] = i;
		dfs(res, depth+1, i+1);
	}
}

int
find_dist(pair<int, int>& home, pair<int, int>& chicken) {
	return abs(home.first - chicken.first) + abs(home.second - chicken.second);
}

void
fill_dist() {
  for (int i = 0; i < n_home; ++i) {
    for (int j = 0; j < n_chicken; ++j) {
      dist[i][j] = find_dist(home[i], chicken[j]);
    }
  }
}
	

int
main(void) {
	cin >> n >> m;
        city.resize(n, vector<int>(n));
	
	int n_home = 0;
	int n_chicken = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int type; cin >> type;
			if (type == 1) {
				home.push_back({i, j});
				n_home += 1;
			}
			if (type == 2) {
				chicken.push_back({i, j});
				n_chicken += 1;
			}
			city[i][j] = type;
		}
	}
        dist.resize(n_home, vector<int>(n_chicken));
	fill_dist();
	vector<int> res(m);
	dfs(res, 0, 0);
        cout << min_dist;
}
