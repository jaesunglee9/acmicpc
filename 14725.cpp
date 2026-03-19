#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <memory>

using namespace std;

struct Node {
	map<string, std::unique_ptr<Node>> next;
	bool is_end = false;

};

void
print(const Node& node, int depth)
{		
	for (const auto& [k, v] : node.next)
	{
		if (v != nullptr)
		{
			for (int i = 0; i < depth; i++)
			{
				cout << "--";
			}
			cout << k << '\n';
			print(*v, depth + 1);
		}
	}
}

void
sol0(vector<vector<string>>& a, int n)
{
	Node root;
	
	for (int i = 0; i < n; i++)
	{
		Node* curr = &root;
		int l = a[i].size();
		for (int j = 0; j < l; j++)
		{
			string str = a[i][j];
			if (curr->next.find(str) == curr->next.end())
			{
				curr->next[str] = make_unique<Node>();
			}

				curr = curr->next[str].get();
			
			if (j == l - 1)
			{
				curr->is_end = true;
			}
		}
	}

	print(root, 0);
}

int
main(void)
{
	int n;
	vector<vector<string>> a;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		int k;

		cin >> k;
		for (int j = 0; j < k; j++)
		{
			string str;

			cin >> str;
			a[i].push_back(str);
		}
	}

	sol0(a, n);
	return 0;
}


				
			
	


    
