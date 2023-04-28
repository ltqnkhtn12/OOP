#include "NhanVien.cpp"

class PartTimeEmployee : public Employee {
    private:
    int workingHour;
    public:
    PartTimeEmployee (string name, int paymentPerHour, int workingHour)  : Employee(name,paymentPerHour) {
        this->workingHour=workingHour;
    }
    public:
    int calculateSalary() {
        return workingHour*getPaymentPerHour();
    }
};