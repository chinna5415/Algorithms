#include <iostream>
#include <cstdlib>
#define nullptr NULL
using namespace std;

class LinkedList {
	public:
		int data;
		LinkedList *prev;
		LinkedList *next;
		
		LinkedList (int val) {
			data = val;
			prev = nullptr;
			next = nullptr;
		}
};

class Node {
	public:
	
		LinkedList *insert_node(int val, LinkedList *chain) {
			
			if (!chain) {
				LinkedList *new_linker = new LinkedList(val);
				chain = new_linker;
				
				return chain;
			} else {
				LinkedList *new_linker = new LinkedList(val);
				
				LinkedList *temp = chain;

				while (temp->next != nullptr) {
					temp = temp->next;
				}
			
				temp->next = new_linker;
				new_linker->prev = temp;
				
				return chain;
			}
		}
		
		LinkedList *insert_node_begging(LinkedList *head, int val) {
			LinkedList *new_linker = new LinkedList(val);
			new_linker->next = head;
			head->prev = new_linker;
			head = new_linker;
			
			return head;
		}
		
		LinkedList *insert_node_end(LinkedList *head, int val) {
			LinkedList *new_linker = new LinkedList(val);
			LinkedList *temp = head;
			
			while (temp->next != nullptr) 
				temp = temp->next;
				
			temp->next = new_linker;
			new_linker->prev = temp;
			
			return head;
		}
		
		LinkedList *insert_node_any_position(LinkedList *head, int ele, int pos) {
			if (pos == 0)
				return insert_node_begging(head,ele);
			
			int count = 0;
			LinkedList *new_linker = new LinkedList(ele);
			LinkedList *ptr = head, *temp;
			
			while (count != pos) {
				temp = ptr;
				ptr = ptr->next;
				count++;
			}
			
			temp->next = new_linker;
			new_linker->prev = temp;
			new_linker->next = ptr;
			ptr->prev = new_linker;
			
			return head;
		}
		
		LinkedList *delete_node_begining(LinkedList *head) {
			LinkedList *temp = head;
			head = temp->next;
			head->prev = nullptr;
			
			delete temp;
			return head;
		}
		
		LinkedList *delete_node_end(LinkedList *head) {
			LinkedList *temp = head;
			
			while (temp->next->next != nullptr)
				temp = temp->next;
				
			temp->next = nullptr;
			return head;
		}
		
		LinkedList *delete_node_at_postion(LinkedList *head,int pos) {
			int count = 0;
			LinkedList *ptr = head, *temp;
			
			while (count != pos) {
				temp = ptr;
				ptr = ptr->next;
				count++;
			}
			
			temp->next = ptr->next;
			ptr->next->prev = temp;
			
			delete ptr;
			return head;
		}
		
		void display(LinkedList *);
};

void Node :: display(LinkedList *head) {
	int count = 0;
	while(head != nullptr) {
		if (count == 0) 
			cout << "present data : " << head->data << endl;
		else
			cout << "present data : " << head->data << "\tprevious : " << head->prev->data << endl;
		head = head->next;
		count++;
	}
}

int main() {
	int limit, get_value;
	
	Node node;
	LinkedList *head = nullptr;
	
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
				cout << "Enter the range : ";
				cin >> limit;

				for (int i = 0; i < limit; i++) {
					cout << "Enter the data : ";
					cin >> get_value;
		
					head = node.insert_node(get_value, head);
				}
				
				break;
			}
			
			case 2 : {
				int ele;
				cout << "enter the data : ";
				cin >> ele;
				head = node.insert_node_begging(head, ele);
				
				break;
			}
			
			case 3 : {
				int ele;
				cout << "enter the data : ";
				cin >> ele;
				head = node.insert_node_end(head,ele);
				
				break;
			}
			
			case 4 : {
				int ele, pos;
				cout << "Enter the ele and pos : ";
				cin >> ele >> pos;
				head = node.insert_node_any_position(head,ele,pos);
				
				break;
			}
			
			case 5 : {
				head = node.delete_node_begining(head);
				
				break;
			}
			
			case 6 : {
				head = node.delete_node_end(head);
				
				break;
			}
			
			case 7 : {
				int pos;
				cout << "Enter the postion : ";
				cin >> pos;
	
				head = node.delete_node_at_postion(head,pos);
				
				break;
			}
			
			case 8 : {
				node.display(head);
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