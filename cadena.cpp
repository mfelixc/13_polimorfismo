#include <iostream>
#include <string>
using namespace std;

class Cadena {
    private:
        string texto;

    public:
        // Constructor
        Cadena(string texto = "");

        // Método que obtiene la longitud
        int longitud();

        // Operador de concatenación
        Cadena operator+(Cadena& c);

        // Operadores de entrada y salida
        friend ostream& operator<<(ostream& os, Cadena c);
        friend istream& operator>>(istream& is, Cadena& c);
};

// Constructor
Cadena::Cadena(string texto) : texto(texto) {
}

// Longitud de la cadena
int Cadena::longitud() {
    return texto.length();
}

// Concatenación
Cadena Cadena::operator+(Cadena& c) {
    return Cadena(texto + c.texto);
}

// Salida de una cadena
ostream& operator<<(ostream& os, Cadena c) {
    os << c.texto;
    return os;
}

// Entrada de una cadena
istream& operator>>(istream& is, Cadena& c) {
    getline(is, c.texto);
    return is;
}

int main() {
    Cadena s1, s2, s3;

    cout << "Ingrese la primera cadena: ";
    cin >> s1;

    cout << "Ingrese la segunda cadena: ";
    cin >> s2;

    s3 = s1 + s2;

    cout << "Concatenacion: " << s3 << endl;
    cout << "Longitud: " << s3.longitud() << endl;

    return 0;
}
