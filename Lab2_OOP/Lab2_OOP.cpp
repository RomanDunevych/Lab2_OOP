#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Complex {
private:
    double x; // дійсна частина
    double y; // уявна частина

public:
    // Конструктор
    Complex(double real = 0, double imag = 0) : x(real), y(imag) {}

    // Константний метод для перетворення до рядка
    string toString() const {
        stringstream sout;
        sout << x << (y >= 0 ? " + " : " - ") << abs(y) << "i";
        return sout.str();
    }

    // Метод для віднімання (з одним параметром)
    Complex sub(const Complex& other) const {
        return Complex(x - other.x, y - other.y);
    }

    // Дружня функція для віднімання (з двома параметрами)
    friend Complex sub(const Complex& a, const Complex& b);

    // Метод для комплексного спряження
    Complex conj() const {
        return Complex(x, -y);
    }

    // Статичний метод для ділення двох комплексних чисел
    static Complex div(const Complex& a, const Complex& b) {
        double denominator = b.x * b.x + b.y * b.y;
        return Complex((a.x * b.x + a.y * b.y) / denominator,
            (a.y * b.x - a.x * b.y) / denominator);
    }

    // Метод виведення значення комплексного числа
    void display() const {
        cout << toString() << endl;
    }
};

// Реалізація дружньої функції для віднімання
Complex sub(const Complex& a, const Complex& b) {
    return Complex(a.x - b.x, a.y - b.y);
}

int main() {
    setlocale(LC_ALL, "UKR");
    Complex c1(4, 5);
    Complex c2(2, -3);

    // Виклик методу віднімання як метод класу
    Complex result1 = c1.sub(c2);
    cout << "Вiднiмання (метод класу): " << result1.toString() << endl;

    // Виклик методу віднімання як дружня функція
    Complex result2 = sub(c1, c2);
    cout << "Вiднiмання (дружня функцiя): " << result2.toString() << endl;

    // Виклик статичного методу для ділення
    Complex result3 = Complex::div(c1, c2);
    cout << "Дiлення (статичний метод): " << result3.toString() << endl;

    // Комплексно спряжене число
    Complex result4 = c1.conj();
    cout << "Комплексно спряжене число: " << result4.toString() << endl;

    return 0;
}
