//Xây dựng lớp đối tượng phương trình bậc 2 (QuadracticEquation) với các thuộc tính hệ số a,b,c
//và các phương thức tính nghiệm của phương trình này

#include <iostream>
#include <math.h>
using namespace std;

//Định nghĩa lớp đối tượng QuadracticEquation
class QuadracticEquation {
private:
	double a;
	double b;
	double c;
public:
	QuadracticEquation(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	double getA() const {
		return a;
	}
	void setA(double a) {
		this->a = a;
	}
	double getB() const {
		return b;
	}
	void setB(double b) {
		this->b = b;
	}
	double getC() const {
		return c;
	}
	void setC(double c) {
		this->c = c;
	}
	double getDiscriminant() const {
		return b * b - 4 * a * c;
	}

	double getRoot() const {
		if (getDiscriminant()<0)
		{
			return 0;
		}
		return (-b) / (2 * a);
	}
	double getRoot1() const {
		if (getDiscriminant() < 0) {
			return 0;
		}
		return (-b + sqrt(getDiscriminant())) / (2 * a);
	}
	double getRoot2() const {
		if (getDiscriminant() < 0) {
			return 0;
		}
		return (-b - sqrt(getDiscriminant())) / (2 * a);
	}
};
//Kiểm tra kết quả bằng cách tạo đối tượng QuadracticEquation và tính nghiệm của phương trình
int main() {
	QuadracticEquation equation(1, -5, 6);
	double delta = equation.getDiscriminant();
	if (delta < 0) {
		cout << "The equation has no real roots" << endl;
	}
	else if (delta==0) {
		cout << "The equation has one root: " << equation.getRoot() << endl;
	}
	else {
		double root1 = equation.getRoot1();
		double root2 = equation.getRoot2();
		cout << "The equation has two roots: " << root1 <<  " and " << root2 << endl;
	}
	return 0;
}