//ejercicio 3: promedio notas
#include <iostream>
#include <string>

using namespace std;

const int maxEstu = 100;
const int maxMaterias = 100;

const double promBajo = 60.0;
const double promMedio = 75.0;
const double promAlto = 90.0;

void ordenarAscendente(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ordenarDescendente(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void promedioNotas() {
    int numEstudiantes, numMaterias;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> numEstudiantes;
    cout << "Ingrese la cantidad de materias: ";
    cin >> numMaterias;
    
    double calificaciones[maxEstu][maxMaterias];
    double promediosEstudiantes[maxEstu] = {0};
    double promediosMaterias[maxMaterias] = {0};
    string nombresEstudiantes[maxEstu];
    string nombresMaterias[maxMaterias];
    
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> nombresEstudiantes[i];
    }
    
    for (int j = 0; j < numMaterias; j++) {
        cout << "Ingrese el nombre de la materia " << j + 1 << ": ";
        cin >> nombresMaterias[j];
    }
    
    for (int i = 0; i < numEstudiantes; i++) {
        for (int j = 0; j < numMaterias; j++) {
            cout << "Ingrese la calificación del estudiante " << nombresEstudiantes[i] << " en la materia " << nombresMaterias[j] << ": ";
            cin >> calificaciones[i][j];
            promediosEstudiantes[i] += calificaciones[i][j];
            promediosMaterias[j] += calificaciones[i][j];
        }
        promediosEstudiantes[i] /= numMaterias;
    }
    
    for (int j = 0; j < numMaterias; j++) {
        promediosMaterias[j] /= numEstudiantes;
    }
    
    int estudiantesBajo = 0, estudiantesMedio = 0, estudiantesAlto = 0;
    for (int i = 0; i < numEstudiantes; i++) {
        if (promediosEstudiantes[i] < promBajo) {
            estudiantesBajo++;
        } else if (promediosEstudiantes[i] < promMedio) {
            estudiantesMedio++;
        } else {
            estudiantesAlto++;
        }
    }
    
    char opcion;
    cout << "¿Desea ordenar los promedios de forma ascendente (a) o descendente (d)? ";
    cin >> opcion;
    
    if (opcion == 'a' || opcion == 'A') {
        ordenarAscendente(promediosEstudiantes, numEstudiantes);
        ordenarAscendente(promediosMaterias, numMaterias);
    } else if (opcion == 'd' || opcion == 'D') {
        ordenarDescendente(promediosEstudiantes, numEstudiantes);
        ordenarDescendente(promediosMaterias, numMaterias);
    } else {
        cout << "Opción inválida. Se mostrarán los promedios sin ordenar.\n";
    }
    
    cout << "\nPromedios por estudiante:\n";
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Estudiante: " << nombresEstudiantes[i] << " - Promedio: " << promediosEstudiantes[i] << "\n";
    }
    
    cout << "\nPromedios por materia:\n";
    for (int j = 0; j < numMaterias; j++) {
        cout << "Materia: " << nombresMaterias[j] << " - Promedio: " << promediosMaterias[j] << "\n";
    }
    
    cout << "\nClasificación de promedios:\n";
    cout << "Estudiantes con promedio bajo (<" << promBajo << "): " << estudiantesBajo << "\n";
    cout << "Estudiantes con promedio medio (<" << promMedio << "): " << estudiantesMedio << "\n";
    cout << "Estudiantes con promedio alto (>=" << promAlto << "): " << estudiantesAlto << "\n";
}

int main() {
    promedioNotas();
    return 0;
}