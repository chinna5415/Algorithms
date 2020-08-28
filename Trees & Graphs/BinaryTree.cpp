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
		
		Node *MIN(Node *min_) {
			while (min_->left != nullptr)
				min_ = min_->left;
			return min_;
		}
		
	 	void insert_node(Node *, int);
	 	void Delete_node(Node *, int);
		void PreOrder(Node *);
		void InOrder(Node *);
		void PostOrder(Node *);
		
};

void Tree :: insert_node(Node *root, int ele) {
	if (root->data > ele) {
		if (root->left == nullptr) {
			Node *new_linker = new Node(ele);
			root->left = new_linker;
			return;
		} else {
			insert_node(root->left, ele);
		}
	} else {
		if (root->right == nullptr) {
			Node *new_linker = new Node(ele);
			root->right = new_linker;
			return;
		} else {
			insert_node(root->right, ele);
		}
	}
}

void Tree :: Delete_node(Node *root, int ele) {
	Node *temp = nullptr;
	Node *ptr = root;
	
	while (ptr != nullptr and ptr->data != ele) {
		temp = ptr;
		
		if (ele < ptr->data)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	
	if (ptr == nullptr)
		return;
		
	if (ptr->left == nullptr and ptr->right == nullptr) {
		if (ptr != root) {
			if (temp->left == ptr)
				temp->left = nullptr;
			else
				temp->right = nullptr;
		} else {
			root = nullptr;
		}
		
		delete ptr;
	} else if (ptr->left and ptr->right) {
		Tree tree;
		Node *minimum = tree.MIN(ptr->right);
		int key = minimum->data;
		
		Delete_node(root, minimum->data);
		
		ptr->data = key;
	} else {
		Node *node = (ptr->left) ? ptr->left : ptr->right;
		
		if (ptr != root) {
			if (ptr == temp->left)
				temp->left = node;
			else
				temp->left = node;
		} else {
			root = node;
		}
		
		delete ptr;
	}
}

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
		cout << "\n5.Insert Node";
		cout << "\n6.Delete Node";
		cout << "\n7.EXIT";
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
			
			case 5: {
				int ele;
				cout << "Enter the inserted data : ";
				cin >> ele;
				mytree.insert_node(root, ele);
				break;
			}
			
			case 6: {
				int ele;
				cout << "Enter the ele to element : ";
				cin >> ele;
				mytree.Delete_node(root, ele);
				break;
			}
			
			case 7 : {
				cout << "Bye!";
				exit(0);
			}
		}
	}
	
	return 0;
}
