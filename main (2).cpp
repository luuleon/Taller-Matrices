// Ejercicio 2: Piscina
#include <iostream>
#include <cstring>

using namespace std;

const int maxFilas = 100;
const int maxColumnas = 100;

void simularPelota(int piscina[maxFilas][maxColumnas], int filas, int columnas, int filaInicial, int columnaInicial) {
    int filaActual = filaInicial;
    int columnaActual = columnaInicial;
    int ruta[maxFilas * maxColumnas][2];
    int rutaSize = 0;
    
    while (true) {
        ruta[rutaSize][0] = filaActual;
        ruta[rutaSize][1] = columnaActual;
        rutaSize++;
        
        int maxProfundidad = piscina[filaActual][columnaActual];
        int nuevaFila = filaActual;
        int nuevaColumna = columnaActual;
        
        // Buscar la baldosa esa
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                
                int nuevaFila = filaActual + i;
                int nuevaColumna = columnaActual + j;
                
                if (nuevaFila >= 0 && nuevaFila < filas &&
                    nuevaColumna >= 0 && nuevaColumna < columnas &&
                    piscina[nuevaFila][nuevaColumna] > maxProfundidad) {
                    maxProfundidad = piscina[nuevaFila][nuevaColumna];
                    filaActual = nuevaFila;
                    columnaActual = nuevaColumna;
                }
            }
        }
        
        // Verificar si se alcanzó un sumidero
        if (filaActual == nuevaFila && columnaActual == nuevaColumna) {
            break;
        }
    }
    
    // Mostrar la rut y la pos final
    cout << "Ruta seguida por la pelota:\n";
    for (int i = 0; i < rutaSize; i++) {
        cout << "(" << ruta[i][0] << ", " << ruta[i][1] << ")\n";
    }
    cout << "Posición final: (" << filaActual << ", " << columnaActual << ")\n";
}

int main() {
    int filas, columnas;
    cout << "Ingrese el número de filas de la piscina: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de la piscina: ";
    cin >> columnas;

    int piscina[maxFilas][MAX_COLUMNAS];
    cout << "Ingrese los valores de profundidad de la piscina:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> piscina[i][j];
        }
    }

    int filaInicial, columnaInicial;
    cout << "Ingrese la fila inicial donde se lanza la pelota: ";
    cin >> filaInicial;
    cout << "Ingrese la columna inicial donde se lanza la pelota: ";
    cin >> columnaInicial;

    simularPelota(piscina, filas, columnas, filaInicial, columnaInicial);

    return 0;
}




