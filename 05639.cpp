#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to easily create a new node
    Node(int value) {
        data = value;
        left = nullptr; // A new node has no children initially
        right = nullptr;
    }
};


void
post(Node* curr) {
	if (curr == nullptr) return;

	post(curr->left);
	post(curr->right);
	cout << curr->data << '\n';
}
	

int
main(void) {
	vector<int> a;
	int n;
	while (cin >> n) {
		a.push_back(n);
	}

	Node* tree = new Node(a[0]);
	for (int i = 1; i < a.size(); i++) {
		int v = a[i];
		Node* curr = tree;
		while (1) {
			if (v < curr->data){
				if (curr->left) curr = curr->left;
				else {curr->left = new Node(v); break; }
			}
			else {
				if (curr->right) curr = curr->right;
				else {curr->right = new Node(v); break;}
			}
			
		}	
	}

	post(tree);

	return 0;
}
		
