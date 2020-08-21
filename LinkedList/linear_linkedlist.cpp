#include <iostream>
#include <cstdlib>
#define nullptr NULL
using namespace std;

class Linkedlist{
	public:
		int data;
		Linkedlist *next;
		
		Linkedlist(int val) {
			this->data = val;
			this->next = nullptr;
		}
};

class Node {
	public:
		Linkedlist *head;
		Linkedlist *tail;
		
		Node() {
			this->head = nullptr;
			this->tail = nullptr;
		}
		
		void insert_node(int);	
		void search(int, Linkedlist *);	
		
		Linkedlist *insert_node_begining(Linkedlist *head) {
			int new_data;
			cout << "enter the data : ";
			cin >> new_data;
			
			Linkedlist *new_linker = new Linkedlist(new_data);
			cout << "data : " << new_linker->data;
			
			new_linker->next = head;
			head = new_linker;
			
			return head;
		}
		
		Linkedlist *insert_node_end(Linkedlist *head) {
			int new_data;
			cout << "enter the data ";
			cin >> new_data;
			
			Linkedlist *new_linker = new Linkedlist(new_data);
			new_linker->next = nullptr;
			Linkedlist *ptr = head;
			
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			
			ptr->next = new_linker;
			return head;
		}
		
		Linkedlist *insert_position(int pos, Linkedlist *head) {
			int new_data, count = 0;
			cout << "enter the data : ";
			cin >> new_data;
			
			Linkedlist *new_linker = new Linkedlist(new_data);
			Linkedlist *ptr = head, *temp;
			
			while (count != pos && ptr != nullptr) {
				temp = ptr;
				ptr = ptr->next;
				count++;
			}
			
			temp->next = new_linker;
			new_linker->next = ptr;
			
			return head; 
		}
		
		Linkedlist *delete_begining(Linkedlist *head) {
			Linkedlist *temp = head;
			head = head->next;
			delete temp;
			return head;
		}
		
		Linkedlist *delete_end(Linkedlist *head) {
			Linkedlist *ptr = head;
			
			while (ptr->next->next != nullptr) {
				ptr = ptr->next;
			}
			
			ptr->next = nullptr;
			
			return head;
		}
		
		Linkedlist *delete_posistion(int pos, Linkedlist *head) {
			int count = 0;
			Linkedlist *ptr = head, *temp;
			while (count != pos && ptr != nullptr){
				temp = ptr;
				ptr = ptr->next;
				count++;
			}
			
			temp->next = ptr->next;
			return head;
		}
};

void Node :: insert_node(int val) {
	Linkedlist *linker = new Linkedlist(val);
	
	if (!this->head)
		this->head = linker;
	else
		this->tail->next = linker;
		
	this->tail = linker;
}

void Node :: search(int ele, Linkedlist *head) {
	while (head != nullptr) {
		if (head->data == ele) {
			cout << "\nElement found" << endl;
			return; 
		}
		head = head->next;
	}
	
	cout << "\nElement not found" << endl;
}

void DISPLAY(Linkedlist *head) {
	if (head == nullptr) return;
	cout << head->data << endl;
	DISPLAY(head->next);
}

int main() {
	int limit, get;
	
	Node *node = new Node();
	
	while (1) {
		int option;
		cout << "\n1.CREATE LINKED LIST\n";
		cout << "\n2.Insert Node at Begining\n";
		cout << "\n3.Insert Node at End\n";
		cout << "\n4.Insert Node at Position\n";
		cout << "\n5.Delete Node at Begining\n";
		cout << "\n6.Delete Node at End\n";
		cout << "\n7.Delete Node at Position\n";
		cout << "\n8.Display\n";
		cout << "\n9.EXIT\n";
		cout << "\nchoose your option : ";
		cin >> option;
		
		switch(option) {
			case 1 : {
				cout << "Enter the range of the Linked list : ";
				cin >> limit;
				
				for (int i = 0; i < limit; i++) {
					cout << "Enter the data : ";
					cin >> get;
					node->insert_node(get);
				}
				
				break;
			}
			
			case 2 : {
				if (node->head == nullptr) 
					cout << "\nFrist create the Linked List\n";
				else
			  		node->head = node->insert_node_begining(node->head);
				break;	
			}
			
			case 3 : {
				if (node->head == nullptr) 
					cout << "\nFrist create the Linked List\n";
				else
					node->head = node->insert_node_end(node->head);
				break;
			}
			
			case 4 : {
				if (node->head == nullptr) 
					cout << "\nFrist create the Linked List\n";
				else {
					int position;
					cout << "enter the position : ";
					cin >> position;
					node->head = node->insert_position(position, node->head);	
				}
				
				break;
			}
			
			case 5 : {
				if (node->head == nullptr) 
					cout << "\nFrist create the Linked List\n";
				else
					node->head = node->delete_begining(node->head);
				break;
			}
			
			case 6 : {
				if (node->head == nullptr) 
					cout << "\nFrist create the Linked List\n";
				else
					node->head = node->delete_end(node->head);
				break;
			}
			
			case 7 : {
				if (node->head == nullptr) 
					cout << "\nFrist create the Linked List\n";
				else {
					int position;
					cout << "enter the postion to perform deletion : ";
					cin >> position;
	
					node->head = node->delete_posistion(position, node->head);
				}
				
				break;
			}
			
			case 8 : {
				if (node->head == nullptr) 
					cout << "\nFrist create the Linked List\n";
				else {
					cout << "<======== CONTENTS ============>" << endl;
					DISPLAY(node->head);
				}
				
				break;
			}
			
			case 9 : {
				cout << "\nBye\n";
				exit(0);
			}
			
			default : cout << "\n Invaild option\n";
		}
	}
	
	
	return 0;
}
