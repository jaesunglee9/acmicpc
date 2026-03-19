#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int
main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	unordered_map<string, int> um;
	string str;
	
	while(getline(cin, str)) {
		um[str] += 1;
	}

	int cnt = 0;
	vector<string> trees;
	for (auto it = um.begin(); it != um.end(); it++) {
		trees.push_back(it->first);
		cnt += it->second;
	}

	sort(trees.begin(), trees.end());

	cout << fixed << setprecision(4);
	
	for(int i = 0; i < trees.size(); i++) {
		cout << trees[i] << " " << float(um[trees[i]]) / cnt * 100.0 << '\n';
	}

	return 0;
}
