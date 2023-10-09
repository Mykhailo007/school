#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void print() {
        cout << "<" << first << ", " << second << ">" << endl;
    }
};

int main() {
    Pair<int, double> p1(1, 7.3);
    Pair<string, double> p2("hello", 7.7);
    Pair<float, long> p3(1.2, 777777773);
    Pair<long, string> p4(1234567890, "yeo");
    Pair<int, int> p5(3, 4);

    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();

    cout << abs(-2) << endl;

    return 0;
}