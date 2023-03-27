//Xây dựng đối tượng điện thoại (phone) và các thuộc tính chung như hãng sản xuất và năm sản xuất
//Xây dựng các lớp con điện thoại thông minh (SmartPhone), điện thoại cơ bản (BasicPhone) kế thừa từ lớp cha phone
//Và cài đặt các phương thức riêng cho từng lớp con như chụp ảnh, gọi điện thoại

#include <iostream>
#include <string>
using namespace std;

class Phone {
private:
	string brand;
	int year;
public:
	Phone(string brand, int year) {
		this->brand = brand;
		this->year = year;
	}
	string getBrand() const {
		return brand;
	}
	int getYear() const {
		return year;
	}
	virtual void takePhoto() const = 0;
	virtual void makeCall() const = 0;
};

class SmartPhone : public Phone {
public:
	SmartPhone(string brand, int year) : Phone(brand, year) {}
	void takePhoto() const override {
		cout << "Take photo with smartphone..." << endl;
	}
	void makeCall() const override {
		cout << "Making call with smartphone..." << endl;
	}
};

class BasicPhone : public Phone {
public:
	BasicPhone(string brand, int year) : Phone(brand, year) {}
	void takePhoto() const override {
		cout << "Cannot take photo with basicphone!" << endl;
	}
	void makeCall() const override {
		cout << "Making call with basicphone..." << endl;
	}
};

int main() {
	Phone* phone1 = new SmartPhone("Samsung", 2020);
	Phone* phone2 = new BasicPhone("Nokia", 2000);

	phone1->takePhoto();
	phone1->makeCall();

	phone2->takePhoto();
	phone2->makeCall();
	
	return 0;
}