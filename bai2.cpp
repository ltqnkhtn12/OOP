//Xây dựng lớp đối tượng hình hộp chữ nhật (Cuboid) với các thuộc tính độ dài, độ rộng và độ cao
//và các phương thức tính thể tích và diện tích bề mặt của hình hợp chữ nhật

#include <iostream>
using namespace std;

class Rectangle {
private:
	double length;
	double width;
public:
	Rectangle(double l, double w) {
		length = l;
		width = w;
	}
	double getLength() const {
		return length;
	}
	double getWidth() const {
		return width;
	}
	void setLength(double l) {
		length = l;
	}
	void setWidth(double w) {
		width = w;
	}
	double getArea() const {
		return length * width;
	}
	double getPerimeter() const {
		return 2 * (length + width);
	}
};
//Định nghĩa lớp đối tượng Cuboid kế thừa từ lớp Rectangle
class Cuboid : public Rectangle {
private:
	double height;
public:
	Cuboid(double l, double w, double h) : Rectangle(l, w) {
		height = h;
	}
	double getHeight() const {
		return height;
	}
	void setHeight(double h) {
		height = h;
	}
	double getVolume() const {
		return getArea() * height;
	}
	double getSurfaceAre() const {
		return 2 * getArea() * getLength() + getArea() * getHeight() + getLength();
	}
};
//Kiểm tra kết quả bằng cách tạo đối tuongj Cuboid và tính toán thể tích và diện tích bề mặt
int main() {
	Cuboid cuboid(3, 4, 5);
	cout << "Volume: " << cuboid.getVolume() << endl;
	cout << "Surface Area: " << cuboid.getSurfaceAre() << endl;
	return 0;
}
