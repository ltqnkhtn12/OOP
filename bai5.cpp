//Xây dựng lớp đối tượng người (Person) với các thuộc tính tên, tuổi và địa chỉ
//và các phương thức nhập và xuất thông tin người

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
	string address;
public:
	Person(string name, int age, string address) {
		this->name = name;
		this->age = age;
		this->address = address;
	}
	string getName() const{
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	int getAge() const {
		return age;
	}
	void setAge(int age) {
		this->age = age;
	}
	string getAddress() {
		return address;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void display() const {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Address: " << address << endl;
	}
};
//Kiểm tra kết quả bằng cách tạo đối tượng Person và hiển thị thông tin của nó
int main() {
	Person person("Nhu", 23, "Thanh pho Ho Chi Minh");
    person.display();
	return 0;
}