#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef string Elem;

class LinkedBinaryTree {
 protected:
  struct Node {                                            // a node of the tree
    Elem elt;                                              // element value
    Node *par;                                             // parent
    Node *left;                                            // left child
    Node *right;                                           // right child
    Node() : elt(), par(NULL), left(NULL), right(NULL) {}  // constructors
  };

 public:
  class Position {  // position in the tree
   private:
    Node *v;  // pointer to the node
   public:
    Position(Node *_v = NULL) : v(_v) {}  // constructor
    Elem &operator*() {                   // get element
      return v->elt;
    }
    Position left() const {  // get left child
      return Position(v->left);
    }
    Position right() const {  // get right child
      return Position(v->right);
    }
    Position parent() const {  // get parent
      return Position(v->par);
    }
    bool isRoot() const {  // root of the tree
      return v->par == NULL;
    }
    bool isExternal() const {  // an external node
      return v->left == NULL && v->right == NULL;
    }
    friend class LinkedBinaryTree;  // give tree access
  };

  typedef list<Position> PositionList;  // list of positions

 public:
  LinkedBinaryTree();                      // constructor
  //~LinkedBinaryTree();                     //destructor
  int size() const;                        // number of nodes
  bool empty() const;                      // is tree empty?
  Position root() const;                   // get root
  void addRoot();                          // add root to empty tree
  void expandExternal(const Position &p);  // expand external node
  void expandLeft(const Position &p);
  Position removeAboveExternal(const Position &p);  // remove p and parent
  int isOperator(const string &element) const;      // checks for operators
  void printExpression();                           // prints postfix expression
  double evaluateExpression(double a,
                            double b);  // compute expression inputting a and b
  double getScore() const;              // get score variable
  void setScore(double _score);         // set score variable
  bool operator<(const LinkedBinaryTree &LBT) const;  // compare score

 protected:
  void preorder(Node *v, PositionList &pl) const;   // preorder utility
  void postorder(Node *v, PositionList &pl) const;  // postorder utility
  void inorder(Node *v, PositionList &pl) const;    // inorder utility

 private:
  Node *_root;  // pointer to the root
  int n;        // number of nodes
  double score;
  void printExpression(Position p);
  double evaluateExpression(double a, double b, Position p);
};

LinkedBinaryTree::LinkedBinaryTree()
    : _root(NULL), n(0), score(0) {}  // constructor

/*LinkedBinaryTree::~LinkedBinaryTree() { 
    stack<Node*> toDelete;
    toDelete.push(root);
    while (!toDelete.empty()) {
        Node* current = toDelete.top();
        toDelete.pop();
        if (current->left != nullptr) 
            toDelete.push(current->left);
        else if (current->right != nullptr)
            toDelete.push(current->right);
        delete current;
    }
}*/

int LinkedBinaryTree::size() const {  // number of nodes
  return n;
}

bool LinkedBinaryTree::empty() const {  // is the tree empty?
  return size() == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {  // get the root
  return Position(_root);
}

void LinkedBinaryTree::addRoot() {  // add root to the empty tree
  _root = new Node;
  n = 1;
  _root->elt = n;
}

void LinkedBinaryTree::expandExternal(
    const Position &p) {  // expand external node
  Node *v = p.v;          // p's node
  v->left = new Node;     // add a new left child
  v->left->par = v;       // v is its parent
  v->right = new Node;    // add a new right child
  v->right->par = v;      // v is its paren
  n += 2;                 // number of nodes increased by 2
}

void LinkedBinaryTree::expandLeft(const Position &p) {
  Node *v = p.v;
  v->left = new Node;
  v->left->par = v;
  n++;
}

void LinkedBinaryTree::preorder(Node *v, PositionList &pl) const {
  pl.push_back(Position(v));
  if (v->left)  // traverse left branch
    preorder(v->left, pl);
  if (v->right)  // traverse right branch
    preorder(v->right, pl);
}

void LinkedBinaryTree::postorder(Node *v, PositionList &pl) const {
  if (v->left)  // traverse left branch
    postorder(v->left, pl);
  if (v->right)  // traverse right branch
    postorder(v->right, pl);
  pl.push_back(Position(v));
}

void LinkedBinaryTree::inorder(Node *v, PositionList &pl) const {
  if (v->left)  // traverse left branch
    inorder(v->left, pl);
  pl.push_back(Position(v));
  if (v->right)  // traverse right branch
    inorder(v->right, pl);
}

int LinkedBinaryTree::isOperator(const string &symbol) const {
  if (symbol == "-" || symbol == "+" || symbol == "*" || symbol == "/" ||
      symbol == ">") {  // check for normal operators
    return 1;
  }

  else if (symbol == "abs") {  // check for abs operator
    return 2;
  }

  return 0;  // non operators
}

void LinkedBinaryTree::printExpression() {  // recursively print tree as
                                            // expression
  Position p = root();  // start at root

  if (p.isExternal()) {  // print number
    cout << *p;
  }

  else if (isOperator(*p) == 2) {  // print abs operator
    cout << *p << "(";
    printExpression(p.left());  // traverse left branch
    cout << ")";
  } else {  // print normal operators
    cout << "(";
    printExpression(p.left());  // traverse left branch
    cout << *p;
    printExpression(p.right());  // traverse right branch
    cout << ")";
  }
}

void LinkedBinaryTree::printExpression(Position p) {
  if (p.isExternal()) {  // print leaf value
    cout << *p;
  }

  else if (isOperator(*p) == 2) {  // print abs operator
    cout << *p << "(";
    printExpression(p.left());  // traverse left branch
    cout << ")";
  } else {  // print normal operators
    cout << "(";
    printExpression(p.left());  // traverse left branch
    cout << *p;
    printExpression(p.right());  // traverse right branch
    cout << ")";
  }
}

double LinkedBinaryTree::evaluateExpression(double a, double b) {
  Position p = root();
  if (p.isExternal()) {  // is leaf

    if (*p == "a")  // return value
      return a;
    else if (*p == "b")  // return value
      return b;
    else
      return stod(*p);  // return converted double
  } else {              // traverse branches and perform operations
    if (*p == "abs") {  // special case for 'abs'
      double x = evaluateExpression(a, b, p.left());  // traverse left child
      return abs(x);
    } else {                                           // perform operations
      double x = evaluateExpression(a, b, p.left());   // left child
      double y = evaluateExpression(a, b, p.right());  // right child

      if (*p == "+")
        return x + y;
      else if (*p == "-")
        return x - y;
      else if (*p == "*")
        return x * y;
      else if (*p == "/")
        return x / y;
      else if (x > y)
        return 1;
      else
        return -1;
    }
  }
}

double LinkedBinaryTree::evaluateExpression(double a, double b, Position p) {
  if (p.isExternal()) {  // is leaf
    if (*p == "a")       // return value
      return a;

    else if (*p == "b")  // return value
      return b;

    else
      return stod(*p);                                // return converted double
  } else {                                            // perform operations
    if (*p == "abs") {                                // special case for 'abs'
      double x = evaluateExpression(a, b, p.left());  // left child
      return abs(x);
    } else {
      double x = evaluateExpression(a, b, p.left());   // left child
      double y = evaluateExpression(a, b, p.right());  // right child

      if (*p == "+")
        return x + y;
      else if (*p == "-")
        return x - y;
      else if (*p == "*")
        return x * y;
      else if (*p == "/")
        return x / y;
      else if (x > y)
        return 1;
      else
        return -1;
    }
  }
}

double LinkedBinaryTree::getScore() const {
  return score;
}  // return score of tree

void LinkedBinaryTree::setScore(double _score) {
  score = _score;
}  // set score of tree

bool LinkedBinaryTree::operator<(
    const LinkedBinaryTree &other) const {  // overload '<' operator
  return score < other.getScore();
}

LinkedBinaryTree createExpressionTree(string postfix) {
  stack<string> aStack;
  stringstream ss(postfix);
  LinkedBinaryTree arbre = LinkedBinaryTree();  // call constructor
  string sample;
  bool isLeft = false;  // add to left or right node
  arbre.addRoot();      // create root
  LinkedBinaryTree::Position pNode =
      arbre.root();  // create position node at tree root

  while (ss >> sample) {
    aStack.push(sample);
  }

  *pNode = aStack.top();  // set elt of pNode to elt at the top of the stack
  aStack.pop();           // pop/remove after stored

  if (*pNode == "abs") {
    arbre.expandLeft(pNode);  // create one child under 'abs' operator
    isLeft = 1;
  } else if (arbre.isOperator(*pNode)) {
    arbre.expandExternal(pNode);  // create two nodes under operator
  } else {
    return arbre;
  }

  int sizeofStack = aStack.size();

  for (int i = 0; i < sizeofStack; i++) {
    if (arbre.isOperator(aStack.top()) == 2) {  // abs operator
      pNode = pNode.left();     // set position node to left child
      *pNode = aStack.top();    // set node element to top stack element
      aStack.pop();             // remove element from stack
      arbre.expandLeft(pNode);  // add one child under 'abs'
      isLeft = 1;               // currently on left child
    } else if (arbre.isOperator(aStack.top()) == 1) {  // other operators
      pNode = pNode.left();         // set position node to left child
      *pNode = aStack.top();        // set node element to top stack element
      aStack.pop();                 // remove element from stack
      arbre.expandExternal(pNode);  // add two children under operators
      isLeft = 0;                   // add right child first during next loop
    } else {
      LinkedBinaryTree::Position curNode;  // save new node's postition

      if (isLeft == 0) {
        curNode = pNode.right();  // set current node as right child
        *curNode = aStack.top();  // set node element to top stack element
        aStack.pop();             // remove element from stack
        isLeft = 1;               // add left child first during next loop
      } else {
        curNode = pNode.left();   // set current node as left child
        *curNode = aStack.top();  // set node element to top stack element
        aStack.pop();             // renive element from stack
        isLeft = 0;               // add right child first during next loop
      }
    }
  }
  return arbre;
}

int main() {
  // Read postfix expressions into vector
  vector<LinkedBinaryTree> trees;
  ifstream exp_file("expressions.txt");
  string line;
  while (getline(exp_file, line)) {
    trees.push_back(createExpressionTree(line));
  }
  // Read input data into 2D vector
  vector<vector<double>> inputs;
  ifstream input_file("input.txt");
  while (getline(input_file, line)) {
    vector<double> ab_input;
    stringstream ss(line);
    string str;
    while (getline(ss, str, ' ')) {
      ab_input.push_back(stod(str));
    }
    inputs.push_back(ab_input);
  }
  // Evaluate expressions on input data
  for (auto &t : trees) {
    double sum = 0;
    for (auto &i : inputs) {
      sum += t.evaluateExpression(i[0], i[1]);
    }
    t.setScore(sum / inputs.size());
  }
  // Sort trees by their score
  sort(trees.begin(), trees.end());
  for (auto &t : trees) {
    cout << "Exp ";
    t.printExpression();
    cout << " Score " << t.getScore() << endl;
  }
}
