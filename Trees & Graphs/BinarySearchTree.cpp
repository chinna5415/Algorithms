#include <iostream>
#define nullptr NULL
using namespace std;

class Node {
	public:
	
		int data;
		Node *right;
		Node *left;
	
		Node (int data) {
			this->data = data;
			this->right = nullptr;
			this->left = nullptr;
		}
};

class Tree {
	public:
		Node *insert_data(int val, Node *linker) {
			if (linker == nullptr) 
				return new Node(val);
			else {
				Node *node;
				if (val <= linker->data) {
					node = insert_data(val, linker->left);
					linker->left = node;
				} else {
					node = insert_data(val, linker->right);
					linker->right = node;
				}
				
				return linker;
			}
		} 
};

void Search(Node *root, int ele) {
	if (root->data == ele) {
		cout << "Found";
		return;
	} else if (root->data > ele) {
		
		if (root->left == nullptr) {
			cout << "Not Found";
			return;
		}
			
		Search(root->left, ele);
	} else {
		
		if (root->right	 == nullptr) {
			cout << "Not Found";
			return;
		}
		
		Search(root->right, ele);
	}
}

void MINIMUM(Node *root) {
	if (root->left == nullptr) {
		cout << "Min Element is : " << root->data;
		return;
	}
	MINIMUM(root->left);
}

void MAXIMUM(Node *root) {
	if (root->right == nullptr) {
		cout << "Max Element is : " << root->data;
		return;
	}
	MAXIMUM(root->right);
}

int main() {
	int limit, get, option;
	
	Tree mytree;
	Node *root = nullptr;
	
	while (1) {
		cout << "\n1.Create Tree";
		cout << "\n2.Search An Element";
		cout << "\n3.Min Element";
		cout << "\n4.Max Element";
		cout << "\n5.EXIT";
		cout << "\nchoose your option : ";
		cin >> option;
		
		switch (option) {
			case 1 : {
				cout << "Enter the limit : ";
				cin >> limit;
				
				for (int i = 0; i < limit; i++) {
					cout << "Enter the data : ";
					cin >> get;
					root = mytree.insert_data(get, root);
				}
				
				break;
			}
			
			case 2 : {
				int ele;
				cout << "Enter the element to search : ";
				cin >> ele;
				Search(root,ele);
				
				break;
			}
			
			case 3 : {
				MINIMUM(root);
				break;
			}
			
			case 4 : {
				MAXIMUM(root);
				break;
			}
			
			case 5 : {
				cout << "Bye!";
				exit(0);
			}
		}
	}
	
	return 0;
}