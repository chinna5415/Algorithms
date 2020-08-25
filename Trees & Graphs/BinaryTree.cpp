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
		
		void PreOrder(Node *);
		void InOrder(Node *);
		void PostOrder(Node *);
		
};

void Tree :: PreOrder(Node *root) {
	/*
		Traversal Order : RLR --> Root Left Right
	*/
	
	if (root == nullptr) return;
	cout << " -> " << root->data;
	PreOrder(root->left);
	PreOrder(root->right);
	
}

void Tree :: InOrder(Node *root) {
	/*
		Traversal Order : LRR --> Left Root Right
	*/
	
	if (root == nullptr) return;
	InOrder(root->left);
	cout << " -> " << root->data;
	InOrder(root->right);
	
}

void Tree :: PostOrder(Node *root) {
	/*
		Traversal Order : LRR --> Left Right Root
	*/
	
	if (root == nullptr) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << " -> " << root->data;
	
}

int main() {
	int limit, get, option;
	
	Tree mytree;
	Node *root = nullptr;
	
	while (1) {
		cout << "\n1.Create Tree";
		cout << "\n2.PreOrder Traversal";
		cout << "\n3.InOrder Traversal";
		cout << "\n4.PostOrder Traversal";
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
				cout << "\n ======== PREORDER =======\n";
				mytree.PreOrder(root);
				cout << "\n";
				break;
			}
			
			case 3 : {
				cout << "\n ======== INORDER =======\n";
				mytree.InOrder(root);
				cout << "\n";
				break;
			}
			
			case 4: {
				cout << "\n ======== INORDER =======\n";
				mytree.PostOrder(root);
				cout << "\n";
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