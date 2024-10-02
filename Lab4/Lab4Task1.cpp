#include <iostream>
#include <cstddef>
using namespace std;
class ListNode{
public:
	int data;
	ListNode	*next;
	ListNode	*prev;
};
class DoublyLinkedList{
public:
	ListNode *first; // special variable which stores address of head node.
	ListNode *last; // special variable which stores address of the last node.

	ListNode *PredLoc_; //to be used by Search(value) method to store address of logical predecessor of value in a list.
	ListNode *Loc_; //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.
    DoublyLinkedList();
    void insertNewNode(int val);
    void reverse();
    void display();
};
// Constructor
DoublyLinkedList::DoublyLinkedList(){
		first = NULL; 		
        last = NULL;
		PredLoc_= NULL;	
        Loc_= NULL;
};
// Adding elements to the linked list
void DoublyLinkedList::insertNewNode(int value) {
	ListNode *newnode = new ListNode();
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (first == NULL) {
		// If the list is empty, new node becomes both first and last
		first = last = newnode;
	} else {
		// Insert at the end
		last->next = newnode;
		newnode->prev = last;
		last = newnode;
	}
}

// Reversing the list
void DoublyLinkedList :: reverse(){
    ListNode *current = first;
    ListNode *temp = NULL;

    //Traversing through the entire list while swapping the next and the previous position for each node
    while (current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev; //move to the prev node
    }
    if(temp != NULL){
        first = temp->prev;
    }
}

// displaying the linked list
void DoublyLinkedList::display(){
    ListNode *current = first;
    while(current != NULL){
        cout << current->data << endl;
        current = current->next;
    } 
    cout << endl;
}
int main() {
    DoublyLinkedList dll;
    dll.insertNewNode(10);
    dll.insertNewNode(20);
    dll.insertNewNode(40);
    dll.insertNewNode(30);  
    
    // Original List
    cout << "Original List: "<<endl;
    dll.display();

    // Reversed List
    cout <<  "Reversed List: "<<endl;
    dll.reverse();
    dll.display();

    return 0;
}

