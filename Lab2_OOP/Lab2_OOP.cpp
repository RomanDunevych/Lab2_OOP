#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Complex {
private:
    double x; // ����� �������
    double y; // ����� �������

public:
    // �����������
    Complex(double real = 0, double imag = 0) : x(real), y(imag) {}

    // ����������� ����� ��� ������������ �� �����
    string toString() const {
        stringstream sout;
        sout << x << (y >= 0 ? " + " : " - ") << abs(y) << "i";
        return sout.str();
    }

    // ����� ��� �������� (� ����� ����������)
    Complex sub(const Complex& other) const {
        return Complex(x - other.x, y - other.y);
    }

    // ������ ������� ��� �������� (� ����� �����������)
    friend Complex sub(const Complex& a, const Complex& b);

    // ����� ��� ������������ ���������
    Complex conj() const {
        return Complex(x, -y);
    }

    // ��������� ����� ��� ������ ���� ����������� �����
    static Complex div(const Complex& a, const Complex& b) {
        double denominator = b.x * b.x + b.y * b.y;
        return Complex((a.x * b.x + a.y * b.y) / denominator,
            (a.y * b.x - a.x * b.y) / denominator);
    }

    // ����� ��������� �������� ������������ �����
    void display() const {
        cout << toString() << endl;
    }
};

// ��������� ������� ������� ��� ��������
Complex sub(const Complex& a, const Complex& b) {
    return Complex(a.x - b.x, a.y - b.y);
}

int main() {
    setlocale(LC_ALL, "UKR");
    Complex c1(4, 5);
    Complex c2(2, -3);

    // ������ ������ �������� �� ����� �����
    Complex result1 = c1.sub(c2);
    cout << "�i��i����� (����� �����): " << result1.toString() << endl;

    // ������ ������ �������� �� ������ �������
    Complex result2 = sub(c1, c2);
    cout << "�i��i����� (������ �����i�): " << result2.toString() << endl;

    // ������ ���������� ������ ��� ������
    Complex result3 = Complex::div(c1, c2);
    cout << "�i����� (��������� �����): " << result3.toString() << endl;

    // ���������� �������� �����
    Complex result4 = c1.conj();
    cout << "���������� �������� �����: " << result4.toString() << endl;

    return 0;
}
