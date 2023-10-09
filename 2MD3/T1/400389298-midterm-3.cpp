#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Deque {
private:
//private variables
    vector<string> data; //vector to store deque elements
    int capacity; //maximum capacity of deque
    int head; //index of the head of deque
    int tail; //index of the tail of deque
    int dequeSize; //current size of deque

public:

    Deque(int n){ //constructor to create deque of size n
        capacity = n;
        head = 0;
        tail = -1;
        dequeSize = 0;
        data.resize(n);}


    void insertFront(string s); //insert element at front of deque
    void insertBack(string s); //insert element at back of deque
    void eraseFront(); //remove element from front of deque
    void eraseBack(); //remove element from back of deque
    string front(); //return element at front of deque
    string back(); //return element at back of deque
    int size(); //return current size of deque
    bool empty(); // check if deque is empty
    void print(); //print deque elements
};

void Deque::insertFront(string s) {
//check if deque is full
    if (dequeSize == capacity) {
        cout << "Error: Deque is full" << endl; return;}
        //update head index and insert element at front of deque
        head = (head + capacity - 1) % capacity;
        data[head] = s;
        dequeSize++;}

void Deque::insertBack(string s) {
    //check if deque is full
    if (dequeSize == capacity) {
        cout << "Error: Deque is full" << endl; return;}
    //update tail index and insert element at back of deque
    tail = (tail + 1) % capacity;
    data[tail] = s;
    dequeSize++;}

void Deque::eraseFront() {
    //check if deque is empty
    if (dequeSize == 0) {
        cout << "Error: Deque is empty" << endl; return;}
    //erase element at front of deque
    data[head] = " ";
    //update head index
    head = (head + 1) % capacity;
    dequeSize--;}

void Deque::eraseBack() {
    //check if deque is empty
    if (dequeSize == 0) {
        cout << "Error: Deque is empty" << endl; return;}
    //erase element at back of deque
    data[tail] = " ";
    //update tail index
    tail = (tail - 1) % capacity;
    dequeSize--;}

string Deque::front() {
    //check if deque is empty
    if (data.empty()) {
        cout << "Error: Deque is empty" << endl; return EXIT_SUCCESS;}
    //return element at front of deque
    return data[head];}

string Deque::back() {
    //check if deque is empty
    if (data.empty()) {
        cout << "Error: Deque is empty" << endl; return EXIT_SUCCESS;}
    //return element at back of deque
    return data[tail];}

int Deque::size() {
    //return current size of deque
    return dequeSize;}

bool Deque::empty() {
    //check if deque is empty
    if (dequeSize == 0) return true;
    else if (dequeSize > 0) return false;
    return false;}

void Deque::print() {
    for (int i = 0; i < dequeSize; i++) {
        cout << data[i] << ' ';}
    cout << endl;}



/*
int main() {
    Deque deq(10);
    deq.insertFront("hello");
    deq.insertBack("world");
    deq.insertBack("lol");
    deq.insertFront("testing");
    deq.insertFront("hell");
    deq.insertBack("word");
    deq.insertBack("lo");
    deq.insertFront("test");
    deq.insertFront("ello");
    deq.insertBack("worl");
    deq.print();
    deq.insertBack("ol");
    deq.insertFront("tester");
    for(int k=0;k<4;k++){
        deq.eraseBack();
    }
    for(int j=0;j<4;j++){
        deq.eraseFront();
    }
    deq.print();
    deq.front();
    deq.back();
    cout << deq.size() << endl;
    cout << deq.empty() << endl;

    return EXIT_SUCCESS;
}*/

int main() {
    Deque dq(5);

    dq.insertFront("a");
    dq.insertBack("b");
    dq.insertBack("c");
    dq.insertFront("d");
    dq.insertBack("e");

    cout << "front: " << dq.front() << endl;
    cout << "back: " << dq.back() << endl;
    cout << "size: " << dq.size() << endl;

    dq.eraseFront();
    dq.eraseBack();

    cout << "front: " << dq.front() << endl;
    cout << "back: " << dq.back() << endl;
    cout << "size: " << dq.size() << endl;

    dq.eraseFront();
    dq.eraseBack();

    cout << "front: " << dq.front() << endl;
    cout << "back: " << dq.back() << endl;
    cout << "size: " << dq.size() << endl;

    dq.eraseBack();
    dq.eraseFront();

    cout << "front: " << dq.front() << endl;
    cout << "back: " << dq.back() << endl;
    cout << "size: " << dq.size() << endl;

    return 0;
}