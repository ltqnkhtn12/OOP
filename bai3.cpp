//Bài 3: Xây dựng lớp đối tượng phân số (Fraction với các thuộc tính tử số và mẫu số
//và các phương thức tính tổng, hiệu, tích, thương.

#include <iostream>
using namespace std;

class Fraction {
private:
	int numerator;
	int demoninator;
public:
	Fraction(int n, int d) {
		numerator = n;
		demoninator = d;
		}
	int getNumerator() {
		return numerator;
	}
	int getDemoninator() {
		return demoninator;
	}
	Fraction add(Fraction f) {
		int n = numerator * f.demoninator + f.numerator * demoninator;
		int d = demoninator * f.demoninator;
		return Fraction(n, d);
	}
	Fraction substract(Fraction f) {
		int n = numerator * f.demoninator - f.numerator * demoninator;
		int d = demoninator * f.demoninator;
		return Fraction(n, d);
	}
	Fraction multiply(Fraction f) {
		int n = numerator * f.numerator;
		int d = demoninator * f.demoninator;
		return Fraction(n, d);
	}
	Fraction divide(Fraction f) {
		int n = numerator * f.demoninator;
		int d = demoninator * f.numerator;
		return Fraction(n, d);
	}
};

int main() {
	Fraction f1(1, 2); //Khởi tạo đối tượng phân số 1/2
	Fraction f2(3, 4); //Khởi tạo đối tượng phân số 3/4
	Fraction f3 = f1.add(f2);
	Fraction f4 = f1.substract(f2);
	Fraction f5 = f1.multiply(f2);
	Fraction f6 = f1.divide(f2);
	cout << "Fraction 1: " << f1.getNumerator() << "/" << f1.getDemoninator() << endl;
	cout << "Fraction 2: " << f2.getNumerator() << "/" << f2.getDemoninator() << endl;
	cout << "Sum of fraction: " << f3.getNumerator() << "/" << f3.getDemoninator() << endl;
	cout << "Difference of fraction: " << f4.getNumerator() << "/" << f4.getDemoninator() << endl;
	cout << "Product of fraction: " << f5.getNumerator() << "/" << f5.getDemoninator() << endl;
	cout << "Quotient of fraction: " << f6.getNumerator() << "/" << f6.getDemoninator() << endl;
}
