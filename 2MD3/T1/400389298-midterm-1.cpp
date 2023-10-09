// include required libraries
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Stack {

public:
    void push(double x);   //push a double value into the stack
    double pop();          //remove and return the top element from the stack
    double peek();         //return the top element from the stack
    bool empty();          //check if the stack is empty
    int size();            //return the size of the stack

private:
    stack<double> stackBase; //stack container for storing double values

};

//push a double value into the stack
void Stack::push(double x){
    stackBase.push(x);}

//remove and return the top element from the stack
double Stack::pop(){
    double temp = stackBase.top();
    stackBase.pop();
    return temp;}

//return the top element from the stack
double Stack::peek(){
    return stackBase.top();}

//check if the stack is empty
bool Stack::empty(){
    return stackBase.empty();}

//return the size of the stack
int Stack::size(){
    return stackBase.size();}


class RPNEvaluator {
private:
    string RPNexpression;

public:
    RPNEvaluator(const string& expression)
        : RPNexpression(expression) {}

    //method to evaluate the RPN expression and return the result
    double Evaluate() {
        Stack stack;                    //create a stack object for storing values
        stringstream ss(RPNexpression); //initialize stringstream with RPNexpression
        
        while (ss) {                    //loop until stringstream is empty
            string symbol;
            ss >> symbol;               //extract next symbol
            
            if (symbol.empty()) {       //skip empty tokens
                continue;}
            else if (isdigit(symbol[0])) { //symbol is a number
                double val = stod(symbol);
                stack.push(val);}
            else if (symbol.size() == 1 && string("+-*/").find(symbol) != string::npos) {
                // operator symbol (+, -, *, /)
                double a = stack.pop();
                double b = stack.pop();

                switch (symbol[0]) {
                    case '+': stack.push(b + a); break;
                    case '-': stack.push(b - a); break;
                    case '*': stack.push(b * a); break;
                    case '/': stack.push(b / a); break;}}
            else {
                cerr << "Invalid symbol: " << symbol << endl; 
                //print error message for invalid symbol
                return EXIT_SUCCESS;} //return 0 as result
        }

        return stack.pop(); // return the final result of the RPN expression
    }

};


int main(){
    string rpn_exp;
    cout << "Please enter an expression in RPN format: ";
    getline(cin, rpn_exp);
    RPNEvaluator rpn(rpn_exp);
    cout << rpn.Evaluate() << endl;

    return EXIT_SUCCESS;
}