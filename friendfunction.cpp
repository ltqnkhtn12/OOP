//Friend function

#include <iostream>
#include <cmath>
using namespace std;

class Diem {
private:
    float x, y;

public:
    Diem(float a = 0, float b = 0) {
        x = a;
        y = b;
    }

    void nhap() {
        cout << "Nhap toa do x: ";
        cin >> x;
        cout << "Nhap toa do y: ";
        cin >> y;
    }

    void xuat() const {
        cout << "(" << x << ", " << y << ")";
    }

    friend float tinhKhoangCach(const Diem& d1, const Diem& d2);
};

float tinhKhoangCach(const Diem& d1, const Diem& d2) {
    float dx = d1.x - d2.x;
    float dy = d1.y - d2.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Diem d1, d2;
    d1.nhap();
    d2.nhap();

    cout << "Khoang cach giua hai diem ";
    d1.xuat();
    cout << " va ";
    d2.xuat();
    cout << " la " << tinhKhoangCach(d1, d2) << endl;

    return 0;
}
