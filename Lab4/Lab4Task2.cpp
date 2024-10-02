# include <iostream>
# include <cstddef>

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
    ListNode *search(int val);
    void swapNodes(int val1,int val2);
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
// Displaying the double linked list
void DoublyLinkedList::display(){
    ListNode *current = first;
    while(current != NULL){
        cout << current->data << endl;
        current = current->next;
    } 
    cout << endl;
}

// searching for a value in the list
ListNode *DoublyLinkedList::search(int val){
    Loc_ = NULL;
    PredLoc_ = NULL;
    ListNode *current = first;
    while (current != NULL){
        if (current->data == val){
            Loc_ = current;
            return Loc_;
        }
        current = current->next;
    }
    // if the value is not found then return NULL
    return NULL;
}

// Swapping two nodes without changing there values
void DoublyLinkedList::swapNodes(int val1, int val2) {
    ListNode *node1 = search(val1);
    ListNode *node2 = search(val2);
    // check if both values are present in the list and get there address if present
    // or the values are the same
    if (val1 == val2 || node1 == NULL || node2 == NULL){
        cout << "Swap not possible"<<endl;
        return;
    }
        
    // If node1 is not adjacent to node2
    if (node1->next != node2 && node2->next != node1) {
        // Update the prev and next pointers for node1 and node2
        ListNode *node1Prev = node1->prev;
        ListNode *node1Next = node1->next;
        ListNode *node2Prev = node2->prev;
        ListNode *node2Next = node2->next;

        // Change pointers for node1
        if (node1Prev) {
            node1Prev->next = node2;
        } else {
            first = node2; // node1 was head
        }
        if (node2Next) {
            node2Next->prev = node1;
        } else {
            last = node1; // node2 was last
        }
        node2->prev = node1Prev;
        node2->next = node1Next;

        // Change pointers for node2
        if (node2Prev) {
            node2Prev->next = node1;
        } else {
            first = node1; // node2 was head
        }
        if (node1Next) {
            node1Next->prev = node2;
        } else {
            last = node2; // node1 was last
        }
        node1->prev = node2Prev;
        node1->next = node2Next;

    } else { // If node1 and node2 are adjacent
        if (node1->next == node2) { // node1 is before node2
            node1->next = node2->next; 
            node2->prev = node1->prev;
            node2->next = node1; 
            node1->prev = node2; 

            if (node2->next) {
                node2->next->prev = node1; // Update next node of node2
            } else {
                last = node1; // If node1 was last
            }

            if (node1->prev) {
                node1->prev->next = node2; // Update previous node of node1
            } else {
                first = node2; // If node1 was head
            }
        } 
        else { 
            // node2 is before node1
            node2->next = node1->next; 
            node1->prev = node2->prev;
            node1->next = node2; 
            node2->prev = node1; 

            if (node1->next) {
                node1->next->prev = node2; // Update next node of node1
            } else {
                last = node2; // If node2 was last
            }

            if (node2->prev) {
                node2->prev->next = node1; // Update previous node of node2
            } else {
                first = node1; // If node2 was head
            }
        }
    }
}

int main(){
    DoublyLinkedList dll;
    dll.insertNewNode(2);
    dll.insertNewNode(4);
    dll.insertNewNode(24);
    dll.insertNewNode(56);
    dll.insertNewNode(7);
    dll.insertNewNode(98);

    cout << "Original List: " << endl;
    dll.display();

    int val1, val2;
    cout << "Enter the values to swap: " << endl;
    cin >> val1 >> val2;
    dll.swapNodes(val1, val2);

    cout << "List after swapping: " << endl;
    dll.display();
}