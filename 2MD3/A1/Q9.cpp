#include <cstdlib>
#include <iostream>

using namespace std;

class Progression {  //  a generic progression
 public:
  Progression(long f = 0)  // constructor
      : first(f), cur(f) {}
  virtual ~Progression(){};      // destructor
  void printProgression(int n);  // print the first n values
 protected:
  virtual long firstValue();  // reset
  virtual long nextValue();   // advance
 protected:
  long first;  // first value
  long cur;    // current value
};

void Progression::printProgression(int n) {  // print n values
  cout << firstValue();                      // print the first
  for (int i = 2; i <= n; i++)               // print 2 through n
    cout << ' ' << nextValue();
  cout << endl;
}

long Progression::firstValue() {  //  reset
  cur = first;
  return cur;
}
long Progression::nextValue() {  // advance
  return ++cur;
}

class DiffProgression: public Progression { // Difference progression
    public:
    DiffProgression(long f = 200, long  s = 198); // default constructor
    protected:
    virtual long firstValue(); // return to start value
    virtual long nextValue();  // advance
    protected:
        long second;  // second value
        long prev; // previous value
};

DiffProgression::DiffProgression(long f, long s)  // constructor
    : Progression(f), second(s), prev(abs(first-second)) {}

long DiffProgression::nextValue() {  // advance by adding
    long temp = cur;
    cur = abs(cur - prev);
    prev = temp;
    return cur;
}
long DiffProgression::firstValue() { // return to first value in sequence
    cur = first;
    prev = abs(first - second);
    return cur;
}

int main() {
    Progression* prog;
    cout << "Difference progression with default start values:\n";
    prog = new DiffProgression();
    prog->printProgression(10);
    cout << "Difference progression with start values 300 and 297:\n";
    prog = new DiffProgression(300, 297);
    prog->printProgression(10);
}


