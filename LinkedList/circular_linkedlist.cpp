#include <iostream>
#include <cstdlib>
#define nullptr NULL 
using namespace std;

class LinkedList {
	public:
		int data;
		LinkedList *next;
		
		LinkedList(int val) {
			this->data = val;
			this->next = nullptr;
		}	
};

class Node {
	public:
		LinkedList *insert_node(int val, LinkedList *chain) {
			if (chain == nullptr) {
				LinkedList *new_linker = new LinkedList(val);
			
				new_linker->next = new_linker;
				chain = new_linker;
				return chain;
			} else {
				LinkedList *new_linker = new LinkedList(val);
				
				LinkedList *temp = chain;
				while (temp->next != chain)
					temp = temp->next;
					
				temp->next = new_linker;
				new_linker->next = chain;
				
				return chain;
			}
		}
		
		LinkedList *insert_node_at_begining(int ele,LinkedList *head) {
			LinkedList *new_linker = new LinkedList(ele);
			
			LinkedList *temp = head;
			while (temp->next != head)
				temp = temp->next;
				
			temp->next = new_linker;
			new_linker->next = head;
			head = new_linker;
			
			return head;
		}
		
		LinkedList *insert_node_at_end(int ele,LinkedList *head) {
			LinkedList *new_linker = new LinkedList(ele);
			
			LinkedList *temp = head;
			while (temp->next != head)
				temp = temp->next;
				
			temp->next = new_linker;
			new_linker->next = head;
			
			return head;
		}
		
		LinkedList *insert_node_at_any_postion(int ele, int pos, LinkedList	*head) {
			if (pos == 0)
				return insert_node_at_begining(ele, head);
				
			LinkedList *new_linker = new LinkedList(ele);
			LinkedList *ptr = head, *temp;
			int count = 0;
			
			while (count != pos) {
				temp = ptr;
				ptr = ptr->next;
				count++;
			}
			
			temp->next = new_linker;
			new_linker->next = ptr;
			
			return head;
		}
		
		LinkedList *delete_node_at_begining(LinkedList *head) {
			LinkedList *temp = head;
			LinkedList *ptr = head->next;
			
			while (temp->next != head)
				temp = temp->next;
				
			temp->next = ptr;
			head = ptr;
			
			return head;
		}
		
		LinkedList *delete_node_at_end(LinkedList *head) {
			LinkedList *temp = head;
			
			while (temp->next->next != head) 
				temp = temp->next;
				
			temp->next = head;
			return head;
		}
		
		LinkedList *delete_node_at_any_position(int pos,LinkedList *head) {
			if (pos == 0)
				return delete_node_at_begining(head);
				
			LinkedList *ptr = head, *temp;
			int count = 0;
			
			while (count != pos) {
				temp = ptr;
				ptr = ptr->next;
				count++;
			}
			
			temp->next = ptr->next;
			return head;
		}
};

void Display(LinkedList	*head) {
	LinkedList *temp = head;
	while (temp->next != head) {
		cout << temp->data << "\n";
		temp = temp->next;
	}
	cout << temp->data << "\n";
}


int main() {
	int limit, get;
	
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
				cout << "Enter the limit of linkedlist : ";
				cin >> limit;

				for (int i = 0; i < limit; i++) {
					cout << "Enter the data : ";
					cin >> get;
					head = node.insert_node(get, head);
				}
				break;
			}
			
			case 2 : {
				int ele;
				cout << "enter the data : ";
				cin >> ele;
				head = node.insert_node_at_begining(ele, head);
				
				break;
			}
			
			case 3 : {
				int ele;
				cout << "enter the data : ";
				cin >> ele;
				head = node.insert_node_at_end(ele, head);
				
				break;
			}
			
			case 4 : {
				int ele, pos;
				cout << "Enter the ele and postion ";
				cin >> ele >> pos;
				head = node.insert_node_at_any_postion(ele, pos, head);
				
				break;
			}
			
			case 5 : {
				head = node.delete_node_at_begining(head);
				
				break;
			}
			
			case 6 : {
				head = node.delete_node_at_end(head);
				
				break;
			}
			
			case 7 : {
				int pos;
				cout << "Enter the pos : ";
				cin >> pos;
				head = node.delete_node_at_any_position(pos, head);
				
				break;
			}
			
			case 8 : {
				Display(head);
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