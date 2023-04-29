//Class Friend

#include <iostream>
using namespace std;

class B;

class A {
private:
    int a;

public:
    A(int x) {
        a = x;
    }

    friend void display(A obj, B objB);
};

class B {
private:
    int b;

public:
    B(int x) {
        b = x;
    }

    friend void display(A obj, B objB);
};

void display(A obj, B objB) {
    cout << "Gia tri cua a la " << obj.a << endl;
    cout << "Gia tri cua b la " << objB.b << endl;
}

int main() {
    A objA(10);
    B objB(20);
    display(objA, objB);

    return 0;
}
