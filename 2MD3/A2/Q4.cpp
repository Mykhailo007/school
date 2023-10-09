#include <cstdlib>
#include <iostream>
using namespace std;

template <typename E>  // forward declaration of SLinkedList
class SLinkedList;

template <typename E>
class SNode {  // singly linked list node
 private:
  E elem;                       // linked list element value
  SNode<E>* next;               // next item in the list
  friend class SLinkedList<E>;  // provide SLinkedList access
};

template <typename E>
class SLinkedList {  // a singly linked list
 public:
  SLinkedList();              // empty list constructor
  ~SLinkedList();             // destructor
  bool empty() const;         // is list empty?
  const E& front() const;     // return front element
  void addFront(const E& e);  // add to front of list
  void removeFront();         //  remove front of list
  
  int sizeList();
  void printList();
  void appendLists(SLinkedList<E> &secondList);
  void reverseList();
 private:
  SNode<E>* head;  // head of the list

  int sizeList(SNode<E>* v, int count);
  void reverseList(SNode<E>* u);
};

template <typename E>
SLinkedList<E>::SLinkedList()  // constructor
    : head(NULL) {}

template <typename E>
bool SLinkedList<E>::empty() const {  // is list empty?
  return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {  // return front element
  return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {  // destructor
  while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {  // add to front of list
  SNode<E>* v = new SNode<E>;                // create new node
  v->elem = e;                               // store data
  v->next = head;                            // head now follows v
  head = v;                                  // v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() {  // remove front item
  if (head == NULL) return;
  SNode<E>* old = head;  // save current head
  head = old->next;      // skip over old head
  delete old;            // delete the old head
}


template <typename E>
int SLinkedList<E>::sizeList(){
    int count;
    if (head == NULL) count = 0; //checks for empty list
    else {count = sizeList(head, 0);}; //calls the recursive private function 
                                    //from head
    return count;
}


template <typename E>
int SLinkedList<E>::sizeList(SNode<E>* v, int count) {
    if (v->next == NULL) return count+1; //reaches end of singly linked list
    else return sizeList(v->next, count + 1); //recursion implemented
}

template <typename E>
void SLinkedList<E>::printList(){
    if (head == NULL)  cout << "empty list" << endl; //checks for empty list
    SNode<E>* cur = head; //creates a starting point at the head
    for (int i = 0; i < sizeList(); i++){
        //the following is to not ouput an extra '->' once the list ends
        if (cur->next != NULL){ 
        cout << cur->elem << "->";
        cur = cur->next;} //sets the next node to cur
        else {cout << cur->elem << endl;}
    }
}

template <typename E>
void SLinkedList<E>::appendLists(SLinkedList<E> &secondList){
    // Check if the first list is empty
    if (!head) {
        // If it is, set the head of the first list to the head of the second 
        //list
        head = secondList.head;
        // Reset the head of the second list so the destructors don't double 
        //free any memory when they are called
        secondList.head = nullptr;
        return;
    }

    // Start at the head of the first list
    SNode<E>* cur = head; 
    while(cur->next != nullptr){ // Traverse the first list to the end
        cur = cur->next; 
    }
    // Set the next node of the last node of the first list to the head of the 
    //second list
    cur->next = secondList.head;
    // Reset the head of the second list so the destructors don't double free 
    //any memory when they are called
    secondList.head = nullptr;
}

template <typename E>
void SLinkedList<E>::reverseList(){
    if(head == NULL || head->next == NULL)return;
//list is empty or only has one node in it
    reverseList(head);
}

template <typename E>
void SLinkedList<E>::reverseList(SNode<E>* u){
     //if the next node of `u` is NULL, set the head of the list to `u`
    if (u->next  == NULL){
        head = u;
        return;
    }
    //recursively call the `reverseList` function on the next node
    reverseList(u->next);
    //v is set to the next node of u
    SNode<E>* v = u->next;
    //reverse the link by making the next node of v equal to u
    v->next = u;
    u->next = NULL; //set the next node of u to NULL
}
int main() {
  SLinkedList<string> sll1;
  sll1.addFront("four");
  sll1.addFront("three");
  sll1.addFront("two");
  sll1.addFront("one");
  cout << "List one has " << sll1.sizeList() << " nodes:" << endl;
  sll1.printList();

  SLinkedList<string> sll2;
  sll2.addFront("seven");
  sll2.addFront("six");
  sll2.addFront("five");
  cout << "List two has " << sll2.sizeList() << " nodes:" << endl;
  sll2.printList();

  sll1.appendLists(sll2);
  cout << "After appending list 2 to list 1, list 1 has " << sll1.sizeList();
  cout << " nodes:" << endl;
  sll1.printList();
  
  sll1.reverseList();
  cout << "After reversing list 1, it looks like this:" << endl;
  sll1.printList();
}
