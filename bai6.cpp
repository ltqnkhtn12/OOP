//Xây dựng lớp đối tượng Mảng (Array) với các thuộc tính là một mảng số nguyên
//và các phương thức tính tổng, trung bình cộng và tìm phần tử lớn nhất

#include <iostream>
using namespace std;
//Lớp đối tượng Mảng (Array)
class Array {
protected:
	int* arr; //con trỏ đến mảng số nguyên
	int size;
public:
	//Phương thức khởi tạo
	Array(int s) {
		size = s;
		arr = new int[size];
	}
	//Phương thức nhập mảng
	void input() {
		for (int i = 0; i < size;i++) {
			cout << "Nhap phan tu thu" << i << ": ";
			cin >> arr[i];
		}
	}
	//Phương thức xuất mảng
	void output() {
		for (int i = 0;i < size;i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//Phương thức tính tổng
	int sum() {
		int sum = 0;
		for (int i = 0; i < size;i++) {
			sum += arr[i];
		}
		return sum;
	}
	//Phương thức tính trung bình cộng
	double avg() {
		double avg = 0;
		for (int i = 0; i < size;i++) {
			avg += arr[i];
		}
		return avg / size;
	}
	//Phương thức tìm phần tử lớn nhất
	int max() {
		int max = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}
};

//Lớp đối tượng mảng nguyên kế thừa lớp đối tượng mảng
class IntArray : public Array {
	public:
		//Phương thức khởi tạo
		IntArray(int s) : Array (s) {}
		//Phương thức nhập mảng số nguyên
		void input() {
			for (int i = 0;i < size;i++) {
				cout << "Nhap phan tu thu"<<i<<": ";
				cin >> arr[i];
			}
		}
	};
//Hàm chính main
int main() {
	//Khởi tạo đối tượng Mảng nguyên với kích thước 5
	IntArray arr(5);
	//Nhập mảng
	cout << "Nhap mang so nguyen: \n";
	arr.input();
	//xuất mảng
	cout << "Mang da nhap: ";
	arr.output();
	//Tính tổng
	cout << "Tong: " << arr.sum() << endl;
	//Tính trung bình cộng
	cout << "Trung binh cong: " << arr.avg() << endl;
	//Tìm phần tử lớn nhất
	cout << "Phan tu lon nhat: " << arr.max() << endl;
	return 0;
}