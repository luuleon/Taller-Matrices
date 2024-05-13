//ejercicio 6: cajeero automatico
#include <iostream>

using namespace std;

int main() {
    double saldo = 1000.0, limiteDiario = 500.0, retirosDelDia = 0.0, deposito, retiro, transferencia, comision = 5.0;
    int opcion;

    do {
        cout << "\nBienvenido al cajero automático\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Depositar dinero\n";
        cout << "3. Retirar dinero\n";
        cout << "4. Realizar transferencia\n";
        cout << "8. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Su saldo actual es: $" << saldo << "\n";
                break;
            case 2:
                cout << "Ingrese la cantidad a depositar: $";
                cin >> deposito;
                saldo += deposito;
                cout << "Depósito exitoso. Su nuevo saldo es: $" << saldo << "\n";
                break;
            case 3:
                cout << "Ingrese la cantidad a retirar: $";
                cin >> retiro;
                if (retiro > saldo) {
                    cout << "Saldo insuficiente\n";
                } else if (retiro + retirosDelDia > limiteDiario) {
                    cout << "Límite diario de retiro excedido\n";
                } else {
                    saldo -= retiro;
                    retirosDelDia += retiro;
                    cout << "Retiro exitoso. Su nuevo saldo es: $" << saldo << "\n";
                }
                break;
            case 4:
                cout << "Ingrese la cantidad a transferir: $";
                cin >> transferencia;
                if (transferencia > saldo) {
                    cout << "Saldo insuficiente\n";
                } else {
                    saldo -= transferencia + comision;
                    retirosDelDia += transferencia;
                    cout << "Transferencia exitosa. Se ha debitado $" << transferencia + comision << " de su cuenta\n";
                    cout << "Su nuevo saldo es: $" << saldo << "\n";
                }
                break;
            case 8:
                cout << "Gracias por usar nuestro cajero automático\n";
                break;
            default:
                cout << "Opción inválida\n";
        }
    } while (opcion != 8);

    return 0;
}
