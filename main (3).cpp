// Ejercicio 1: Punto de Silla
#include <iostream>
#include <cstring>

using namespace std;

const int maxFilas = 100;
const int maxColumnas = 100;

bool esPuntoDeSilla(int matriz[maxFilas][maxColumnas], int filas, int columnas, int fila, int columna) {
    int valor = matriz[fila][columna];
    
    //pa mirar fila
    for (int i = 0; i < columnas; i++) {
        if (matriz[fila][i] < valor) {
            return false;
        }
    }
    
    //pa mirar columna
    for (int i = 0; i < filas; i++) {
        if (matriz[i][columna] > valor) {
            return false;
        }
    }
    
    return true;
}
int main() {
    int filas, columnas;
    int matriz[maxFilas][maxColumnas];

    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

    cout << "Ingrese los elementos de la matriz:" <<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "Los puntos de silla son: " << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (esPuntoDeSilla(matriz, filas, columnas, i, j)) {
                cout << "(" << i << ", " << j << ") = " << matriz[i][j] << endl;
            }
        }
    }

    return 0;
}


