// Ejercicio 4: Proporciones
#include <iostream>
#include <cstring>

using namespace std;

const int maxFilas = 100;
const int maxColumnas = 100;


int contarPatrones(int matrizGrande[maxFilas][maxColumnas], int filasGrande, int columnasGrande, int patron[maxFilas][maxColumnas], int filasPatron, int columnasPatron) {
    int contador = 0;
    
    for (int i = 0; i <= filasGrande - filasPatron; i++) {
        for (int j = 0; j <= columnasGrande - columnasPatron; j++) {
            bool coincide = true;
            for (int k = 0; k < filasPatron; k++) {
                for (int l = 0; l < columnasPatron; l++) {
                    if (matrizGrande[i + k][j + l] != patron[k][l]) {
                        coincide = false;
                        break;
                    }
                }
                if (!coincide) {
                    break;
                }
            }
            if (coincide) {
                contador++;
            }
        }
    }
    
    return contador;
}
int main() {
    int matrizGrande[maxFilas][maxColumnas];
    int patron[maxFilas][maxColumnas];

    int filasGrande, columnasGrande;
    int filasPatron, columnasPatron;

    cout << "Ingrese el número de filas de la matriz grande: ";
    cin >> filasGrande;
    cout << "Ingrese el número de columnas de la matriz grande: ";
    cin >> columnasGrande;

    cout << "Ingrese la matriz grande (0 o *):" << endl;
    for (int i = 0; i < filasGrande; i++) {
        for (int j = 0; j < columnasGrande; j++) {
            char valor;
            cin >> valor;
            matrizGrande[i][j] = (valor == '*') ? 1 : 0;
        }
    }

    cout << "Ingrese el número de filas del patrón: ";
    cin >> filasPatron;
    cout << "Ingrese el número de columnas del patrón: ";
    cin >> columnasPatron;

    cout << "Ingrese el patrón (0 o *):" << endl;
    for (int i = 0; i < filasPatron; i++) {
        for (int j = 0; j < columnasPatron; j++) {
            char valor;
            cin >> valor;
            patron[i][j] = (valor == '*') ? 1 : 0;
        }
    }

    int coincidencias = contarPatrones(matrizGrande, filasGrande, columnasGrande, patron, filasPatron, columnasPatron);
    cout << "Número de coincidencias del patrón en la matriz grande: " << coincidencias << endl;

    return 0;
}


