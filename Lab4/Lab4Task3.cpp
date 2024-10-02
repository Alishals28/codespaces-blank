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
    void display();
    void rearrangeEvenOdd();
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

// Grouping all the nodes containing even values
void DoublyLinkedList:: rearrangeEvenOdd(){
    // not doing anything if the list is empty
    if (first == NULL){
    }
    ListNode *evenHead = NULL;
    ListNode *evenTail = NULL;
    ListNode *oddHead = NULL;
    ListNode *oddTail = NULL;

    ListNode *current = first;
    while (current != NULL){
        ListNode *nextNode = current->next;
        current->next = NULL;

        if(current->data%2 == 0){
            // for even nodes
            if(evenHead == NULL){
                evenHead = evenTail = current;
            }
            else{
                evenTail->next = current;
                current->prev = evenTail;
                evenTail = current;
            }
        }
        else{
            // for odd nodes
            if (oddHead == NULL){
                oddHead = oddTail = current;
            }
            else{
                oddTail->next = current;
                current->prev = oddTail;
                oddTail = current;
            }
        }
        current = nextNode;
    }
    // connecting the two lists
    if (evenHead != NULL){
        first = evenHead;
        evenTail->next = oddHead;
        if (oddHead != NULL){
            oddHead->prev = evenTail;
            last = oddTail;
        }
        else{
            last = evenTail;
        }
    }
    else{
        first = oddHead;
        last = oddTail;
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

int main(){
    DoublyLinkedList dll;
    dll.insertNewNode(10);
    dll.insertNewNode(15);
    dll.insertNewNode(2);
    dll.insertNewNode(4);
    dll.insertNewNode(9);
    dll.insertNewNode(8);
    dll.insertNewNode(27);

    cout << "Original List: "<< endl;
    dll.display();

    cout << "Rearranged List: " << endl;
    dll.rearrangeEvenOdd();
    dll.display();

    return 0;
}
