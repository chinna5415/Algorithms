using namespace std;
#include <iostream>
#include <new>
#include <cstdlib>

typedef struct node {
    int data;
    struct node *next;
} Hash;

class Hashtable {
  public :
    int length = 5;
    Hash *hash_table[5];

    void null(){
        for (int i = 0 ; i < 5 ; i++)
            hash_table[i] = NULL;
    }

    void data(int length , Hash *hash_table[]);
    void create_hashtable(int length , Hash *hash_table[] , int ele);
    void searching(int length , Hash *hash_table[] , int ele);
    void Delete(int length , Hash *hash_table[] , int ele);
    int hash_function(int length , int ele);
};

void Hashtable :: data(int length , Hash *hash_table[]) {
     int option , ele;
     do {
        cout << "\n1.Insert_An_Element_In_Hash_table\n2.Search_an_Element_in_Hash_table\n3.Delete_an_element_in_Hash_table\n3.Exit";
        cout << "\nchoose your our option : ";
        cin >> option;

        switch (option) {
                case 1 : {
                              cout << "\nenter the element : ";
                              cin >> ele;
                              create_hashtable(length , hash_table , ele);
                              break;
                }
                case 2 : {
                             cout << "\nenter the element to search : ";
                             cin >> ele;
                             searching(length , hash_table , ele);
                             break;
                }
                case 3 : {
                           cout << "\nenter the element to Delete : ";
                           cin >> ele;
                           Delete(length , hash_table , ele);
                           break;
                }
                case 4 : exit(0);
                          break;
                default : cout << "option error!!";
        }
     } while (option < 5);
}

void Hashtable :: create_hashtable(int length , Hash *hash_table[] , int ele) {
     int func = hash_function(length , ele);
     Hash *head = new Hash();
     head->data = ele;
     head->next = NULL;
     Hash *temp = hash_table[func];

     if (temp == NULL)
        hash_table[func] = head;
     else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head;
     }
}

void Hashtable :: searching(int length , Hash *hash_table[] , int ele) {
     int func = hash_function(length , ele);
     int found = 0;
     Hash *temp = hash_table[func];

     if (temp != NULL) {
        while (temp != NULL) {
            if (temp->data == ele)
                found++;
            temp = temp->next;
        }
     }

     (found == 0) ? cout << "element is not found" : cout << "element is found in " << func << "position";
}

void Hashtable :: Delete(int length , Hash *hash_table[] , int ele) {
     int func = hash_function(length , ele);
     Hash *temp1 , *temp2;
     temp1 = hash_table[func];

     if (temp1 != NULL) {
        if (temp1->data == ele)
            hash_table[func] = temp1->next;
        else {
            while (temp1->data != ele) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = temp1->next;
            delete(temp1);
        }
     }
}

int Hashtable :: hash_function(int length , int ele) { return ele%length;}

int main() {
    Hashtable ht;
    ht.null();
    ht.data(ht.length , ht.hash_table);

    return 0;
}
