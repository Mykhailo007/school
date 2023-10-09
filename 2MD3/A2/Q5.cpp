#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class DNode {                // doubly linked list node
 private:
  string name;               // name of score recipiant
  int score;
  DNode* prev;               // previous node in list
  DNode* next;               // next node in list
  friend class DLinkedList;  // allow DLinkedList access
};

class DLinkedList {  // doubly linked list
 public:
  DLinkedList();                    // constructor
  DLinkedList(DLinkedList& dll);    // copy constructor
  ~DLinkedList();                   // destructor
  bool empty() const;               // is list empty?
  const string& frontName() const;  // get front element name
  const int& frontScore() const;    // get front element score
  const string& backName() const;   // get back element name
  const int& backScore() const;     // get back element score
  int Size();                       // count number of elements
  void AddScoreInOrder(std::string name, int score); // add game score
  void RemoveScore(int index);   // removes i'th element of list
  bool UpdateScore(string name, int score);    // update score associated with given name 
                                                    // return true if name was found and updated
  void Print();                  // prints all elements of list
  void operator=(const DLinkedList& dll);
 private:                        // local type definitions
  DNode* header;                 // list sentinels
  DNode* trailer;
  void init();                      // chain default constructor
  void copy(const DLinkedList& dll);      // copies all elements of dll
  void deleteList();                        // delete all elements except sentinels
  int Size(DNode* first, DNode* last, int count); 
  void Print(DNode* currentNode);

 protected:                           // local utilities
  void addFront(const string& name, const int& score);   // add to front of list
  void addBack(const string& name, const int& score);    // add to back of list
  void removeFront();            // remove from front
  void removeBack();             // remove from back
  void add(DNode* v, const string& e, const int& score);  // insert new node before v
  void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList() {  // constructor
    init();
}

DLinkedList::DLinkedList(DLinkedList& dll) {
    init();         // make header and trailer
    copy(dll);
}

DLinkedList::~DLinkedList() {  // destructor
  deleteList();
  delete header;  //  remove the sentinels
  delete trailer;
}

void DLinkedList::init() {
  header = new DNode;      // create sentinels
  trailer = new DNode;
  header->next = trailer;  // have them point to each other
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL;
}



void DLinkedList::deleteList() {
    while (!empty()) {
    removeFront();  //  remove all but sentinels
    }
}

bool DLinkedList::empty() const {  // is list empty?
  return (header->next == trailer);
}

const string& DLinkedList::frontName() const {  // get front element
  return header->next->name;
}

const int& DLinkedList::frontScore() const {
    return header->next->score;
}

const string& DLinkedList::backName() const {  // get back element
  return trailer->prev->name;
}

const int& DLinkedList::backScore() const {
    return trailer->prev->score;
}

void DLinkedList::add(DNode* x, const string& name, const int& score) {
  DNode* newNode = new DNode;
  newNode->name = name;
  newNode->score = score;
  newNode->next = x->next;
  newNode->prev = x;
  x->next->prev = newNode;
  x->next = newNode;
}

void DLinkedList::addFront(const string& name, const int& score) {  // add to front of list
  add(header, name, score);
}

void DLinkedList::addBack(const string& name, const int& score) {  // add to back of list
  add(trailer->prev, name, score);
}

void DLinkedList::remove(DNode* v) {  // remove node v
  DNode* u = v->prev;                 // predecessor
  DNode* w = v->next;                 // successor
  u->next = w;                        // unlink v from list
  w->prev = u;
  delete v;
}

void DLinkedList::removeFront() {  // remove from font
  remove(header->next);
}

void DLinkedList::removeBack() {  // remove from back
  remove(trailer->prev);
}

int DLinkedList::Size() {
    return Size(header->next, trailer->prev, 0); // call the helper function with start and end of list and a count of 0
  }

int DLinkedList::Size(DNode* first, DNode* last, int count) {
    if (first == last) return count + 1; // base case for odd number of elements
    if (first->next == last) return count + 2; // base case for even number of elements

    // recursively call the function with updated first and last pointers and increased count
    return Size(first->next, last->prev, count + 2);
  }

void DLinkedList::AddScoreInOrder(string name, int score) {
    // handle empty list
    if (empty()) {
        addFront(name, score);
        return;
    }
    // initialize current node
    DNode *current = header->next;

    // traverse the list
    while (current != trailer) {
        // if current score is less than the inputted score
        if (current->score < score) {
            // insert the score before the current node
            add(current->prev, name, score);
            return;
        }
        current = current->next; // move to the next node
    }

// add score to the end of the list if no scores are less than inputted score
    addBack(name, score);
}


void DLinkedList::RemoveScore(int index) {
    if (empty()){
        throw std::out_of_range("The list is empty");}
    int len = Size();
    
    if (index < 0 || index >= len){
        throw std::out_of_range("Index is out of bounds");}

    DNode* currentNode = index <= len/2 ? header->next : trailer->prev;
    for (int i = 0; i < abs(len-index); i++) {
        currentNode = index <= len/2 ? currentNode->next : currentNode->prev;
    }
    remove(currentNode);
}

void DLinkedList::Print(DNode* currentNode)
{
    if (currentNode == nullptr) return; //checks if the current node is empty

    cout << "{" << currentNode->name << "," << currentNode->score << "}->";
    // Print the current node's name and score in the desired format
    Print(currentNode->next);    // Call the function on the next node
}

void DLinkedList::Print()
{
    Print(header);    // Call the recursive print function starting 
    //from the head

    cout << endl;    // Add a newline character to the end of the output
}

void DLinkedList::operator=(const DLinkedList& dll){
    if (this == &dll) return;    // Check for self-assignment

    deleteList();

    copy(dll);
}

int main() {
DLinkedList scores;
scores.AddScoreInOrder("Jeff", 7);
scores.AddScoreInOrder("Jen", 9);
scores.AddScoreInOrder("Ilya", 3);
scores.AddScoreInOrder("Sara", 10);
scores.AddScoreInOrder("Sam", 11);
// Test size function
cout << "Number of scores is " << scores.Size() << endl;
scores.Print();
// Test remove function
scores.RemoveScore(3);
cout << "Number of scores is now " << scores.Size() << endl;
scores.Print();
// Test update function
if (scores.UpdateScore("Jeff",6))
    scores.Print();
// Test copy construcor
DLinkedList scores_copy_1(scores);
scores.UpdateScore("Jen",5);
scores.Print();
scores_copy_1.Print();
// Test assignment operator overload
DLinkedList scores_copy_2 = scores_copy_1;
scores_copy_1.UpdateScore("Jen",5);
scores_copy_1.Print();
scores_copy_2.Print();

// Test OrderByName function
scores_copy_2.Print();
}