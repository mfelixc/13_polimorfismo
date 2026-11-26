#include <iostream>
using namespace std;

class Vector {
    private:
        float x;
        float y;

    public:
        // Constructor
        Vector(float x = 0, float y = 0);

        // Operadores binarios
        Vector operator+(Vector& v);
        Vector operator-(Vector& v);


        //operadores
        bool operator*(const Vector& c) const;
        bool operator+=(const Vector& c) const;
        bool operator-=(const Vector& c) const;
        bool operator>>(const Vector& c) const;

        // Operador unario
        Vector operator-();

        // Operador de salida
        friend ostream& operator<<(ostream& os, Vector v);
        friend istream& operator>>(istream& is, Vector& v);
};

//operadores
bool Vector::operator*(const Vector& c) const {
     return Vector(x * c.x, y * c.y); 
    }
bool Vector::operator+=(const Vector& c) const { return x != c.x || y != c.y; }
bool Vector::operator-=(const Vector& c) const  { return x < c.x && y < c.y; }
bool Vector::operator>>(const Vector& c) const  { return x > c.x && y > c.y; }

    
// Constructor
Vector::Vector(float x, float y) : x(x), y(y) {
}

// Suma de vectores
Vector Vector::operator+(Vector& v) {
    return Vector(x + v.x, y + v.y);
}

// Resta de vectores
Vector Vector::operator-(Vector& v) {
    return Vector(x - v.x, y - v.y);
}

// Negación de un vector
Vector Vector::operator-() {
    return Vector(-x, -y);
}

// Salida de un vector
ostream& operator<<(ostream& os, Vector v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
istream& operator>>(istream& is, Vector& v) {
    cout << "Ingrese el valor de x: ";
    is >> v.x;
    cout << "Ingrese el valor de y: ";
    is >> v.y;
    return is;
}

int main() {
    Vector v1(3, 1), v2(1, 2), v3;

    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    v3 = v1 + v2;
    cout << "Suma: " << v3 << endl;

    v3 = v1 - v2;
    cout << "Resta: " << v3 << endl;

    v3 = -v1;
    cout << "Negacion de v1: " << v3 << endl;

    return 0;
}