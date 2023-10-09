#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

typedef std::string Elem;  // base element type

class LinkedBinaryTree {
 protected:
  struct Node {                                            // a node of the tree
    Elem elt;                                              // element value
    Node* par;                                             // parent
    Node* left;                                            // left child
    Node* right;                                           // right child
    Node() : elt(), par(NULL), left(NULL), right(NULL) {}  // constructor
  };

 public:
  class Position {  // position in the tree

   private:
    Node* v;  // pointer to the node

   public:
    Position(Node* v = NULL) : v(v) {}  // constructor
    Elem& operator*() {                 // get element
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
    bool isRoot() const {  // root of the tree?
      return v->par == NULL;
    }
    bool isExternal() const {  // an external node?
      return v->left == NULL && v->right == NULL;
    }

    friend class LinkedBinaryTree;  // give tree access
  };

  typedef std::list<Position> PositionList;  // list of positions

 public:
  LinkedBinaryTree();  // constructor
  //~LinkedBinaryTree();                                            //
  //destructor
  bool isOperator(std::string str) const;           // check if operator
  int size() const;                                 // number of nodes
  bool empty() const;                               // is tree empty?
  Position root() const;                            // get the root
  PositionList positions(int traversal) const;      // list of nodes
  void addRoot();                                   // add root to empty tree
  void expandExternal(const Position& p);           // expand external node
  void expandOne(const Position& p);                // expand a single node
  Position removeAboveExternal(const Position& p);  // remove p and parent
  void printExpression();                           // print expression tree
  double evaluateExpression(
      double a,
      double b);  // evaluate expression given values for variables a and b
  double getScore() const;  // return tree's score
  void setScore(double s);  // set tree's score
  bool operator<(const LinkedBinaryTree& compareTree)
      const;  // compare two LinkedBinaryTrees by their score
  void destroyRecursive(const Position& p);  // delete tree

 protected:                                        // local utilities
  void preorder(Node* v, PositionList& pl) const;  // preorder utility
  void postorder(Node* v, PositionList& pl) const;
  void inorder(Node* v, PositionList& pl) const;

 private:
  Node* _root;                       // pointer to the root
  int n;                             // number of nodes
  double score;                      // score
  void printExpression(Position p);  // print expression tree
  double evaluateExpression(
      double a, double b,
      Position p);  // evaluate expression given values for variables a and b
};

LinkedBinaryTree::LinkedBinaryTree()  // constructor
    : _root(NULL), n(0) {}

// LinkedBinaryTree::~LinkedBinaryTree() {                           //
// destructor
//   destroyRecursive(root);
// }

bool LinkedBinaryTree::isOperator(std::string str) const {  // check if operator
  if (str == "+" || str == "-" || str == "*" || str == "/" || str == ">" ||
      str == "abs") {
    return true;
  } else {
    return false;
  }
}

int LinkedBinaryTree::size() const {  // number of nodes
  return n;
}

bool LinkedBinaryTree::empty() const {  // is tree empty?
  return size() == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {  // get the root
  return Position(_root);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions(
    int traversal) const {  // list of all nodes
  PositionList pl;
  if (traversal == 1)  // preorder traversal
    preorder(_root, pl);
  else if (traversal == 2)  // postorder traversal
    postorder(_root, pl);
  else  // inorder traversal
    inorder(_root, pl);
  return PositionList(pl);  // return resulting list
}

void LinkedBinaryTree::addRoot() {  // add root to empty tree
  _root = new Node;
  n = 1;
  _root->elt = n;
}

void LinkedBinaryTree::expandExternal(
    const Position& p) {  // expand external node
  Node* v = p.v;          // p’s node
  v->left = new Node;     // add a new left child
  v->left->par = v;       // v is its parent
  v->right = new Node;    // and a new right child
  v->right->par = v;      // v is its parent
  n += 2;                 // two more nodes
}

void LinkedBinaryTree::expandOne(const Position& p) {  // expand a single node
  Node* v = p.v;
  v->left = new Node;  // only one child
  v->left->par = v;
  n += 1;  // one more node
}

LinkedBinaryTree::Position  // remove p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p) {
  Node* w = p.v;
  Node* v = w->par;  // get p’s node and parent
  Node* sib = (w == v->left ? v->right : v->left);
  if (v == _root) {  // child of root?
    _root = sib;     // . . .make sibling root
    sib->par = NULL;
  } else {
    Node* gpar = v->par;  // w’s grandparent
    if (v == gpar->left)
      gpar->left = sib;  // replace parent by sib
    else
      gpar->right = sib;
    sib->par = gpar;
  }
  delete w;
  delete v;  // delete removed nodes
  n -= 2;    // two fewer nodes
  return Position(sib);
}

void LinkedBinaryTree::preorder(Node* v,
                                PositionList& pl) const {  // preorder traversal
  pl.push_back(Position(v));                               // add this node
  if (v->left != NULL)  // traverse left subtree
    preorder(v->left, pl);
  if (v->right != NULL)  // traverse right subtree
    preorder(v->right, pl);
}

void LinkedBinaryTree::postorder(
    Node* v, PositionList& pl) const {  // postorder traversal
  if (v->left != NULL)                  // traverse left subtree
    preorder(v->left, pl);
  if (v->right != NULL)  // traverse right subtree
    preorder(v->right, pl);
  pl.push_back(v);
}

void LinkedBinaryTree::inorder(Node* v,
                               PositionList& pl) const {  // inorder traversal
  if (v->left != NULL)  // traverse left subtree
    preorder(v->left, pl);
  pl.push_back(v);
  if (v->right != NULL)  // traverse right subtree
    preorder(v->right, pl);
}

void LinkedBinaryTree::printExpression() {  // print expression tree | base case
  Position p = root();                      // set root
  if (p.isExternal()) {                     // no child
    std::cout << *p;
  } else if (*p == "abs") {  // abs operator
    std::cout << *p << "(";
    printExpression(p.left());  // left child
    std::cout << ")";
  } else {
    std::cout << "(";
    printExpression(p.left());  // left child
    std::cout << *p;
    printExpression(p.right());  // right child
    std::cout << ")";
  }
}

void LinkedBinaryTree::printExpression(Position p) {  // print expression tree
  if (p.isExternal()) {                               // no child
    std::cout << *p;
  } else if (*p == "abs") {  // abs operator
    std::cout << *p << "(";
    printExpression(p.left());  // left child
    std::cout << ")";
  } else {
    std::cout << "(";
    printExpression(p.left());  // left child
    std::cout << *p;
    printExpression(p.right());  // right child
    std::cout << ")";
  }
}

double LinkedBinaryTree::evaluateExpression(
    double a,
    double b) {  // evaluate expression given values for variables a and b
  Position p = root();   // set root
  if (p.isExternal()) {  // no child
    if (*p == "a")
      return a;  // return element
    else if (*p == "b")
      return b;
    return stod(*p);  // convert element from string to double
  } else {
    if (*p == "abs") {  // abs operator
      double x =
          evaluateExpression(a, b, p.left());  // recursion for left child
      return abs(x);
    } else {
      double x = evaluateExpression(a, b, p.left());   // set double x
      double y = evaluateExpression(a, b, p.right());  // set double y

      if (*p == "+")
        return x + y;  // perform operations
      else if (*p == "-")
        return x - y;
      else if (*p == "*")
        return x * y;
      else if (*p == "/")
        return x / y;
      else if (*p == "abs")
        return abs(x);
      else {
        if (*p == ">" && x > y)
          return 1;
        else
          return -1;
      }
    }
  }
}

double LinkedBinaryTree::evaluateExpression(
    double a, double b,
    Position p) {  // evaluate expression given values for variables a and b
  if (p.isExternal()) {  // no child
    if (*p == "a")
      return a;  // return element
    else if (*p == "b")
      return b;
    return stod(*p);  // convert element from string to double
  } else {
    if (*p == "abs") {  // abs operator
      double x =
          evaluateExpression(a, b, p.left());  // recursion for left child
      return abs(x);
    } else {
      double x = evaluateExpression(a, b, p.left());   // set double x
      double y = evaluateExpression(a, b, p.right());  // set double y

      if (*p == "+")
        return x + y;  // perform operations
      else if (*p == "-")
        return x - y;
      else if (*p == "*")
        return x * y;
      else if (*p == "/")
        return x / y;
      else if (*p == "abs")
        return abs(x);
      else {
        if (*p == ">" && x > y)
          return 1;
        else
          return -1;
      }
    }
  }
}

double LinkedBinaryTree::getScore() const {  // return tree's score
  return score;
}

void LinkedBinaryTree::setScore(double s) {  // set tree's score
  score = s;
}

bool LinkedBinaryTree::operator<(const LinkedBinaryTree& compareTree)
    const {  // compare two LinkedBinaryTrees by their score
  return score < compareTree.getScore();
}

LinkedBinaryTree createExpressionTree(
    std::string postfix) {  // build and return binary expression tree
  LinkedBinaryTree tree = LinkedBinaryTree();  // call constructor
  std::stack<std::string> makeStack;
  bool atLeft = 0;  // at left or right side

  std::stringstream ss(postfix);  // separate by space
  std::string substring;
  while (ss >> substring) {
    makeStack.push(substring);  // push onto stack
  }

  tree.addRoot();  // add root to tree
  LinkedBinaryTree::Position posNode =
      tree.root();  // set position node at tree root
  *posNode =
      makeStack
          .top();   // set element of position node to element at top of stack
  makeStack.pop();  // pop after used

  if (*posNode == "abs") {                 // abs operator
    tree.expandOne(posNode);               // add one child under abs operator
    atLeft = 1;                            // added on left side
  } else if (tree.isOperator(*posNode)) {  // operators
    tree.expandExternal(posNode);          // add two children under operator
  } else {
    return tree;
  }  // return tree

  int stackSize = makeStack.size();

  for (int i = 0; i < stackSize; i++) {
    if (tree.isOperator(makeStack.top())) {  // create child for abs operator
      if (makeStack.top() == "abs") {        // abs operator
        posNode = posNode.left();            // position node set to left child
        *posNode = makeStack.top();  // set element at position node to element
                                     // at top of stack
        makeStack.pop();             // pop after used
        tree.expandOne(posNode);     // add two children under operator
        atLeft = 1;  // added on left side (only one child under abs)
      } else {       // create left and right child if operator
        posNode = posNode.left();    // position node set to left child
        *posNode = makeStack.top();  // set element at position node to element
                                     // at top of stack
        makeStack.pop();             // pop after used
        tree.expandExternal(posNode);  // add two children under operator
        atLeft = 0;                    // add right child first for next loop
      }
    } else {
      LinkedBinaryTree::Position curNode;  // new node to save position
      if (atLeft == 1) {
        curNode = posNode.left();  // set current node as left child
        *curNode =
            makeStack
                .top();   // set element of current node to element at stack top
        makeStack.pop();  // pop after used
        atLeft = 0;       // add right child first for next loop
      } else {
        curNode = posNode.right();  // set current node as right child
        *curNode =
            makeStack
                .top();   // set element of current node to element at stack top
        makeStack.pop();  // pop after used
        atLeft = 1;
      }
    }
  }
  return tree;
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
  for (auto& t : trees) {
    double sum = 0;
    for (auto& i : inputs) {
      sum += t.evaluateExpression(i[0], i[1]);
    }
    t.setScore(sum / inputs.size());
  }
  // Sort trees by their score
  sort(trees.begin(), trees.end());
  for (auto& t : trees) {
    cout << "Exp ";
    t.printExpression();
    cout << " Score " << t.getScore() << endl;
  }
}