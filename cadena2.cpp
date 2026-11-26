#include <iostream>
#include <string>
using namespace std;

class Cadena {
    private:
        string texto;

    public:
        Cadena(string texto = "");

        int longitud() const;

        // Concatenación
        Cadena operator+(const Cadena& c) const;

        // Comparación
        bool operator==(const Cadena& c) const;
        bool operator!=(const Cadena& c) const;
        bool operator<(const Cadena& c) const;
        bool operator>(const Cadena& c) const;
        bool operator<=(const Cadena& c) const;
        bool operator>=(const Cadena& c) const;

        // Operador unario
        bool operator!() const;

        // Operador de subíndice
        char operator[](int i) const;

        // Entrada y salida
        friend ostream& operator<<(ostream& os, const Cadena& c);
        friend istream& operator>>(istream& is, Cadena& c);
};

Cadena::Cadena(string texto) : texto(texto) {}

int Cadena::longitud() const { return texto.length(); }

Cadena Cadena::operator+(const Cadena& c) const { return Cadena(texto + c.texto); }

bool Cadena::operator==(const Cadena& c) const { return texto == c.texto; }
bool Cadena::operator!=(const Cadena& c) const { return texto != c.texto; }
bool Cadena::operator<(const Cadena& c) const  { return texto < c.texto; }
bool Cadena::operator>(const Cadena& c) const  { return texto > c.texto; }
bool Cadena::operator<=(const Cadena& c) const { return texto <= c.texto; }
bool Cadena::operator>=(const Cadena& c) const { return texto >= c.texto; }

bool Cadena::operator!() const { return texto.empty(); }

char Cadena::operator[](int i) const {
    if (i < 0 || i >= (int)texto.length()) {
        cout << "Índice fuera de rango" << endl;
        return '\0';
    }
    return texto[i];
}

ostream& operator<<(ostream& os, const Cadena& c) {
    os << c.texto;
    return os;
}

istream& operator>>(istream& is, Cadena& c) {
    getline(is, c.texto);
    return is;
}

int main() {
    Cadena s1, s2, s3;
    int N;

    do {
        cout << "\n=============Menu de opciones=============" << endl;
        cout << "1. Concatenar cadenas" << endl;
        cout << "2. Comparar cadenas" << endl;
        cout << "3. Longitud de la cadena" << endl;
        cout << "4. Negación de la cadena" << endl;
        cout << "5. Subíndice de la cadena" << endl;
        cout << "6. Ingresar cadena" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opción: ";

        if (!(cin >> N)) {              
            cin.clear();
            cin.ignore(1000, '\n');
            N = 0;
        } else {
            cin.ignore(1000, '\n');    
        }

        switch (N) {
            case 1:
                s3 = s1 + s2;
                cout << "Cadena resultante: " << s3 << endl;
                break;
            case 2:
                if (s1 == s2)      cout << "Las cadenas son iguales" << endl;
                else if (s1 < s2)  cout << "La primera es menor que la segunda" << endl;
                else               cout << "La primera es mayor que la segunda" << endl;
                break;
            case 3:
                cout << "Longitud de la primera cadena: " << s1.longitud() << endl;
                cout << "Longitud de la segunda cadena: " << s2.longitud() << endl;
                break;
            case 4:
                cout << "La primera cadena " << (!s1 ? "es vacía" : "no es vacía") << endl;
                cout << "La segunda cadena " << (!s2 ? "es vacía" : "no es vacía") << endl;
                break;
            case 5: {
                int i, n;
                cout << "Ingrese el numero de la cadena (1 o 2): ";
                cin >> n;
                cout << "Ingrese el índice: ";
                cin >> i;
                cin.ignore(1000, '\n');
                if (n == 1)      cout << "Carácter en el índice " << i << ": " << s1[i] << endl;
                else if (n == 2) cout << "Carácter en el índice " << i << ": " << s2[i] << endl;
                else             cout << "Número de cadena no válido" << endl;
                break;
            }
            case 6:
                cout << "Ingrese la primera cadena: ";
                cin >> s1;
                cout << "Ingrese la segunda cadena: ";
                cin >> s2;
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
    } while (N != 7);

    return 0;
}