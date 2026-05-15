#include <iostream>
using namespace std;

int main() {
    double masa, aceleracion, fuerza;
    cout << "Ingrese la masa (kg): ";
    cin >> masa;
    cout << "Ingrese la aceleracion (m/s^2): ";
    cin >> aceleracion;
    
    fuerza = masa * aceleracion;
    
    cout << "La fuerza resultante es: " << fuerza << " Newtons" << endl;
    return 0;
}
