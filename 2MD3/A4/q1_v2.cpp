#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

typedef int Elem;

class LinkedBinaryTree {
protected:

struct Node {
    Elem elt;                   //element value
    Node* par;                  //parent node
    Node* left;                 //left child
    Node* right;                //right child
    Node():elt(), par(NULL), left(NULL), right(NULL) { } //constructors
};

public:

class Position {                //postition in the tree
    private:
        Node* v;                //pointer to node
    public:
        Position(Node* _v = NULL):v(_v) { } //constructor
        Elem& operator*()                   //get element
            {return v->elt;}            
        Position left() const               //get left child
            {return Position(v->left);}
        Position right() const              //get right child
            {return Position(v->right);}
        Position parent() const             //get parent
            {return Position(v->par);}
        
        bool isRoot() const                 //root of tree
            {return v->par == NULL;}
        bool isExternal() const             //leaf of tree
            {return v->left == NULL && v->right == NULL;}
        friend class LinkedBinaryTree;};
typedef list<Position> PositionList;

public:
    LinkedBinaryTree();                     //constructor
    ~LinkedBinaryTree();                    //destructor
    int size() const;                       //number of nodes in tree
    bool empty() const;                     //is tree empty?
    Position root() const;                  //get root of tree
    void addRoot();                         //add root to empty tree
    void expandExternal(const Position& p); //expand external node
    Position removeAboveExternal(const Position& p);    //remove p and parent
    int isOperator(const string& symbol) const;
    void expandLeft(const Position& p);
    

    //helper function
    LinkedBinaryTree createExpressionTree(string postfix){
        stack<LinkedBinaryTree> s;
        stringstream ss(postfix);
        string symbol;
        while (getline(ss, symbol, ' ')) {
            if (!isdigit(symbol)) {
                LinkedBinaryTree right = s.top();
                s.pop();
                LinkedBinaryTree left = s.top();
                s.pop();
                LinkedBinaryTree tree(symbol, left, right);
                s.push(tree);}
            else if (isdigit(symbol)) {
                LinkedBinaryTree tree(symbol);
                s.push(tree);} 
            else {throw runtime_error("Invalid expression");}
        }
        if (s.size() != 1) {
            throw runtime_error("Invalid expression");}
        
        return s.top();};

    //NEW FUNCTIONS

    //Print the postfix notation 
    void printExpression() {
        Node *v = _root;
        if (v.isExternal()) {
            cout << v -> elt
        }
    };

    //evaluate 
    double evaluateExpression( double a, double b) const {
        };

    //get the score of the tree
    double getScore(){return score;};

    //set the score of the tree
    void setScore(double s){score = s;};

    //overload the '<' operator
    bool operator<(const LinkedBinaryTree &other)const 
        {return (score < other.score);};

protected:
    void preorder(Node* v, PositionList& pl) const;         //preorder
    void postorder(Node* v, PositionList& pl) const;        //postorder
    void inorder(Node* v, PositionList& pl) const;          //inorder
private:
    Node* _root;                        //pointer to root
    int n;                              //number of nodes
    double score;                       //score of tree

    //helper functions

    

};

LinkedBinaryTree::LinkedBinaryTree()    //constructor
    : _root(NULL), n(0) { }

int LinkedBinaryTree::size() const      //number of nodes
    {return n;}

bool LinkedBinaryTree::empty() const    //is tree empty
    {return size() == 0;}

LinkedBinaryTree::Position LinkedBinaryTree::root() const //get the root
    {return Position(_root);}

void LinkedBinaryTree::addRoot()        //add root to empty tree
    {_root = new Node; n = 1; }

void LinkedBinaryTree::expandExternal(const Position &p) {
    Node* v = p.v;                      //p's node
    v -> left = new Node;               //add a new left child
    v -> left -> par = v;               //v is its parent
    v -> right = new Node;              //and a new right child
    v -> right -> par = v;              //v is its parent
    n += 2;                             //two new nodes were created
}

void LinkedBinaryTree::expandLeft

LinkedBinaryTree::Position
LinkedBinaryTree::removeAboveExternal(const Position &p) {
    Node *w = p.v;                      //get p's node
    Node *v = w -> par;                 //get p's parent

    Node *sib = (w == v -> left ? v -> right : v -> left);
                                        //assigns sib to be a sibling of w
    if (v == _root) {                   //child of root?
        _root = sib;                    //...make sibling root
        sib -> par = NULL;}
    else {
        Node* gpar = v -> par;          //w's grandparent
        v == gpar -> left ? gpar -> left = sib : gpar -> right = sib;
                                        //replace parent by sib
        //if (v == gpar -> left) gpar -> left = sib;
        //else gpar -> right = sib;
        sib -> par = gpar;
    }
    delete w; delete v;                 //delete removed nodes
    n -= 2;                             //two nodes were removed
    return Position(sib);
}




//private functions

void LinkedBinaryTree::inorder(Node *v) const {
        if (v != nullptr) {
            inOrder(v.left);
            cout << v -> elt << " ";
            inOrder(v.right);
        }
    }



//main

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
