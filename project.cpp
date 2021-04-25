#include <bits/stdc++.h>
#define nullptr NULL
using namespace std;


class Linkedlist{
	public:
		int coeff;
		int pow;
		Linkedlist *next;

		/*
		 	Linkedlist (int , int) -> Parameterized Constructor 

			=> which is used for initialize the variable's

			Linkedlist *next ==> Self-Referential Class

		 */
		
		Linkedlist(int coeff, int pow) {
			this->coeff = coeff;
			this->pow = pow;
			this->next = nullptr;
		}
};

class Node {
	public:
		Linkedlist *head;
		Linkedlist *tail;

		/*
		 	Node() -> Default Constructor

			*head ==> refered to the head of the linkedlist
			*tail ==> refered to the end of the linkedlist
		 */
		
		Node() {
			this->head = nullptr;
			this->tail = nullptr;
		}
		
		void insert_node(int, int);	// Insert the elements into the Linkedlist 
};

void Node :: insert_node(int coeff, int pow) {
	Linkedlist *linker = new Linkedlist(coeff, pow); // creating the node 
	
	if (!this->head)
		this->head = linker;
	else
		this->tail->next = linker;
		
	this->tail = linker;
}

void DISPLAY(Linkedlist *head) {

	if (head == nullptr) { //  If linkedlist is empty it returns the ( Polynomial empyt)
		cout << " POLYNOMIAL EMPTY\n";
		return;
	}

	Linkedlist *temp = head; 
	while (temp != nullptr) { // Displaying the elements
		if (temp->coeff < 0) {
			cout << "- " << -(temp->coeff) << "x^" << temp->pow << " ";
		} else {
			cout << "+ " << temp->coeff << "x^" << temp->pow << " ";
		}

		temp = temp->next; // refered to the next object
	}
}

/*
 	ADDITION( P1, P2) ==> Function performs the addition operation over the polynomials 
 */

void ADDITION(Linkedlist *p1_head, Linkedlist *p2_head) {

	Node *result = new Node(); // creating empty result linkedlist
	Linkedlist *poly1 = p1_head, *poly2 = p2_head;


	/*
	 	WHILE (P1 != NULL AND P2 != NULL):
			IF (P1 != NULL AND P2 != NULL AND P1.POW == P2.POW):
				IF (P1.COEFFICIENT not equal -P2.COEFFICIENT)
					PERFORM ADDTION OPERATION
				ELSE
					PASS TO NEXT

			ELSE IF (P1 != NULL AND P2 == NULL OR P1.POW > P2.POW)
				INSERT P1.COEFFICIENT INTO RESULTANT LIST

			ELSE IF (P2 != NULL AND P1 == NULL OR P2.POW > P1.POW)
				INSERT P2.COEFFICIENT INOT RESULTANT LIST

	 */

	while (poly1 != nullptr and poly2 != nullptr) {
		if ((poly1 != nullptr and poly2 != nullptr) and (poly1->pow == poly2->pow)) {

			if (poly1->coeff != -(poly2->coeff)) {
				result->insert_node(poly1->coeff + poly2->coeff, poly1->pow);
				poly1 = poly1->next;
				poly2 = poly2->next;
			} else {
				poly1 = poly1->next;
				poly2 = poly2->next;
			}

		} else if ((poly1 != nullptr and poly2 == nullptr) or (poly1->pow > poly2->pow)) {
			result->insert_node(poly1->coeff, poly1->pow);
			poly1 = poly1->next;
		} else if ((poly2 != nullptr and poly1 == nullptr) or (poly2->pow > poly1->pow)) {
			result->insert_node(poly2->coeff, poly2->pow);
			poly2 = poly2->next;
		}
	}

	/*
	 	WHILE (P1 != NULL) ==> for remaining elements belongs to p1 
	 */

 	while (poly1 != nullptr) {
		result->insert_node(poly1->coeff, poly1->pow);
		poly1 = poly1->next;
	}

	/*
	 	WHILE (P2 != NULL) ==> for remaining elements belongs to p2
	 */

	while (poly2 != nullptr) {
		result->insert_node(poly2->coeff, poly2->pow);
		poly2 = poly2->next;
	}

	cout << "\n Result Polynomnial : ";
	DISPLAY(result->head);
	cout << "\n";
}

/*
 	SUBTRACTION( P1, P2) ==> Function performs the subraction operation over the polynomials 
 */


void SUBTRACTION(Linkedlist *p1_head, Linkedlist *p2_head) {

	Node *result = new Node();
	Linkedlist *poly1 = p1_head, *poly2 = p2_head;

	/*
	 	WHILE (P1 != NULL AND P2 != NULL):
			IF (P1 != NULL AND P2 != NULL AND P1.POW == P2.POW):
				IF (P1.COEFFICIENT not equal P2.COEFFICIENT)
					PERFORM SUBTRACTION OPERATION
				ELSE
					PASS TO NEXT

			ELSE IF (P1 != NULL AND P2 == NULL OR P1.POW > P2.POW)
				INSERT P1.COEFFICIENT INTO RESULTANT LIST

			ELSE IF (P2 != NULL AND P1 == NULL OR P2.POW > P1.POW)
				INSERT P2.COEFFICIENT INOT RESULTANT LIST

	*/

	while (poly1 != nullptr and poly2 != nullptr) {
		if ((poly1 != nullptr and poly2 != nullptr) and (poly1->pow == poly2->pow)) {

			if (poly1->coeff != poly2->coeff) {
				result->insert_node(poly1->coeff - poly2->coeff, poly1->pow);
				poly1 = poly1->next;
				poly2 = poly2->next;
			} else {
				poly1 = poly1->next;
				poly2 = poly2->next;
			}

		} else if ((poly1 != nullptr and poly2 == nullptr) or (poly1->pow > poly2->pow)) {
			result->insert_node(poly1->coeff, poly1->pow);
			poly1 = poly1->next;
		} else if ((poly2 != nullptr and poly1 == nullptr) or (poly2->pow > poly1->pow)) {
			result->insert_node(-poly2->coeff, poly2->pow);
			poly2 = poly2->next;
		}
	}

	/*
	 	WHILE (P1 != NULL) ==> for remaining elements belongs to p1 
	 */

	while (poly1 != nullptr) {
		result->insert_node(poly1->coeff, poly1->pow);
		poly1 = poly1->next;
	}

	/*
	 	WHILE (P2 != NULL) ==> for remaining elements belongs to p2
	 */

	while (poly2 != nullptr) {
		result->insert_node(-poly2->coeff, poly2->pow);
		poly2 = poly2->next;
	}

	cout << "\n Result Polynomnial : ";
	DISPLAY(result->head);
	cout << "\n";
}

int main() {
	int p1_length, p2_length, coeff, pow, option;
	
	Node *p1 = new Node();
	Node *p2 = new Node();

	cout << "Enter the length of polynomial 1  : ";
	cin >> p1_length;
				
	for (int i = 0; i < p1_length; i++) {
		cout << "Enter the coefficient and power : ";
		cin >> coeff >> pow;
		p1->insert_node(coeff, pow);
	}


	cout << "Enter the length of polynomial 2 : ";
	cin >> p2_length;

	for (int i = 0; i < p2_length; i++) {
		cout << "Enter the coefficient and power : ";
		cin >> coeff >> pow;
		p2->insert_node(coeff, pow);
	}

	cout << "\n POLYNOMIAL 1 : ";	
	DISPLAY(p1->head);
	cout << "\n";

	cout << "\n POLYNOMIAL 2 : ";
	DISPLAY(p2->head);
	cout << "\n";

	cout << "\n[ 1 ] ADDITION \n[ 2 ] SUBTRACTION\n";
	cout << "[ * ] CHOOSE OPTION : ";
	cin >> option;

	if (option == 1)
		ADDITION(p1->head, p2->head);
	else if (option == 2) {
			int op;
			cout << "\n[ 1 ] P1 - P2 \n[ 2 ] P2 - P1\n";
			cout << "[ * ] CHOOSE OPTION : ";
			cin >> op;

			if (op == 1)
				SUBTRACTION(p1->head, p2->head);
			else if (op == 2)
				SUBTRACTION(p2->head, p1->head);
			else
				cout << "\n [ * ] CHOOSE CORRECT OPTION";
	}
	else
		cout << "\n [ * ] CHOOSE CORRECT OPTION";

	return 0;
}
