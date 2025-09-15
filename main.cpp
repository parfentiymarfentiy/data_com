#include <iostream>
using namespace std;

class Fraction {
private:
    int num; 
    int den; 

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void reduce() {
        int common = gcd(abs(num), abs(den));
        num /= common;
        den /= common;
        if (den < 0) { 
            num = -num;
            den = -den;
        }
    }

public:
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d) { reduce(); }
    Fraction(const Fraction& other) : num(other.num), den(other.den) {}

    void print() {
        cout << num << "/" << den;
    }
    
    int getNum() { return num; }
    int getDen() { return den; }

    bool isProper() {
        return abs(num) < abs(den);
    }

    Fraction operator+(int n) {
        return Fraction(num + n * den, den);
    }

    Fraction operator+(Fraction other) {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    Fraction operator-(int n) {
        return Fraction(num - n * den, den);
    }

    Fraction operator-(Fraction other) {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    Fraction operator*(int n) {
        return Fraction(num * n, den);
    }

    Fraction operator*(Fraction other) {
        return Fraction(num * other.num, den * other.den);
    }

    Fraction operator/(int n) {
        return Fraction(num, den * n);
    }

    Fraction operator/(Fraction other) {
        return Fraction(num * other.den, den * other.num);
    }
};

void printResult(const char* op, Fraction f1, Fraction f2, Fraction result) {
    cout << op << " ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " = ";
    result.print();
    cout << endl;
}

void printResult(const char* op, Fraction f1, int n, Fraction result) {
    cout << op << " ";
    f1.print();
    cout << " and " << n << " = ";
    result.print();
    cout << endl;
}

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(5, 6);

    cout << "Fractions: ";
    f1.print(); cout << ", ";
    f2.print(); cout << ", ";
    f3.print(); cout << endl;

    printResult("f1 + 2:", f1, 2, f1 + 2);
    printResult("f1 + f2:", f1, f2, f1 + f2);
    printResult("f2 - 1:", f2, 1, f2 - 1);
    printResult("f2 - f3:", f2, f3, f2 - f3);
    printResult("f3 * 3:", f3, 3, f3 * 3);
    printResult("f2 * f3:", f2, f3, f2 * f3);
    printResult("f3 / 2:", f3, 2, f3 / 2);

    cout << "f1 is proper: " << (f1.isProper() ? "true" : "false") << endl;
    cout << "Fraction(5,2) is proper: " << (Fraction(5,2).isProper() ? "true" : "false") << endl;

    return 0;
}