/*
 * ============================================================
 *  EJERCICIOS 6 – 20  (C++)
 *  Compilar: g++ -o ejercicios ejercicios_6_20.cpp -lm
 * ============================================================
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ============================================================
// EJERCICIO 6: Impuestos y Propina
// ============================================================
void ejercicio6() {
    cout << "\n=== Ejercicio 6: Impuestos y Propina ===" << endl;

    double costo;
    cout << "Ingresa el costo de la comida ($): ";
    cin >> costo;

    const double TASA_IMPUESTO = 0.21;   // IVA España 21 %
    const double TASA_PROPINA  = 0.18;

    double impuesto = costo * TASA_IMPUESTO;
    double propina  = costo * TASA_PROPINA;
    double total    = costo + impuesto + propina;

    cout << fixed << setprecision(2);
    cout << "Impuesto (21%): $" << impuesto << endl;
    cout << "Propina  (18%): $" << propina  << endl;
    cout << "Total         : $" << total    << endl;
}

// ============================================================
// EJERCICIO 7: Suma de los Primeros n Enteros Positivos
// ============================================================
void ejercicio7() {
    cout << "\n=== Ejercicio 7: Suma de 1 a n ===" << endl;

    int n;
    cout << "Ingresa un entero positivo n: ";
    cin >> n;

    long long suma = (long long)n * (n + 1) / 2;
    cout << "La suma de 1 a " << n << " es: " << suma << endl;
}

// ============================================================
// EJERCICIO 8: Widgets y Gizmos
// ============================================================
void ejercicio8() {
    cout << "\n=== Ejercicio 8: Widgets y Gizmos ===" << endl;

    const double PESO_WIDGET = 75.0;   // gramos
    const double PESO_GIZMO  = 112.0;  // gramos

    int widgets, gizmos;
    cout << "Numero de widgets: ";
    cin >> widgets;
    cout << "Numero de gizmos : ";
    cin >> gizmos;

    double pesoTotal = widgets * PESO_WIDGET + gizmos * PESO_GIZMO;
    cout << fixed << setprecision(1);
    cout << "Peso total del pedido: " << pesoTotal << " gramos" << endl;
}

// ============================================================
// EJERCICIO 9: Interés Compuesto
// ============================================================
void ejercicio9() {
    cout << "\n=== Ejercicio 9: Interes Compuesto ===" << endl;

    double saldo;
    const double TASA = 0.04;

    cout << "Ingresa el deposito inicial ($): ";
    cin >> saldo;

    cout << fixed << setprecision(2);
    for (int anio = 1; anio <= 3; anio++) {
        saldo += saldo * TASA;
        cout << "Saldo al final del anio " << anio << ": $" << saldo << endl;
    }
}

// ============================================================
// EJERCICIO 10: Aritmética
// ============================================================
void ejercicio10() {
    cout << "\n=== Ejercicio 10: Aritmetica ===" << endl;

    double a, b;
    cout << "Ingresa a: ";
    cin >> a;
    cout << "Ingresa b: ";
    cin >> b;

    cout << fixed << setprecision(4);
    cout << "Suma      (a + b)    : " << a + b          << endl;
    cout << "Diferencia(a - b)    : " << a - b          << endl;
    cout << "Producto  (a * b)    : " << a * b          << endl;

    if (b != 0) {
        cout << "Cociente  (a / b)    : " << a / b      << endl;
        cout << "Resto     (a %% b)   : " << fmod(a, b) << endl;
    } else {
        cout << "Division y resto: indefinidos (b = 0)" << endl;
    }

    if (a > 0)
        cout << "log10(a)             : " << log10(a)   << endl;
    else
        cout << "log10(a): indefinido (a <= 0)"          << endl;

    cout << "a ^ b                : " << pow(a, b)      << endl;
}

// ============================================================
// EJERCICIO 11: Eficiencia de Combustible (MPG → L/100km)
// ============================================================
void ejercicio11() {
    cout << "\n=== Ejercicio 11: Eficiencia de Combustible ===" << endl;

    // Factor de conversion: 1 MPG = 235.215 / L/100km
    const double FACTOR = 235.215;

    double mpg;
    cout << "Ingresa la eficiencia en MPG: ";
    cin >> mpg;

    if (mpg <= 0) {
        cout << "El valor debe ser positivo." << endl;
        return;
    }

    double l100km = FACTOR / mpg;
    cout << fixed << setprecision(2);
    cout << mpg << " MPG equivale a " << l100km << " L/100km" << endl;
}

// ============================================================
// EJERCICIO 12: Distancia Entre Dos Puntos (fórmula Haversine)
// ============================================================
void ejercicio12() {
    cout << "\n=== Ejercicio 12: Distancia entre dos puntos en la Tierra ===" << endl;

    const double R = 6371.0; // Radio de la Tierra en km
    const double PI = acos(-1.0);

    double lat1, lon1, lat2, lon2;
    cout << "Punto 1 - Latitud  (grados): "; cin >> lat1;
    cout << "Punto 1 - Longitud (grados): "; cin >> lon1;
    cout << "Punto 2 - Latitud  (grados): "; cin >> lat2;
    cout << "Punto 2 - Longitud (grados): "; cin >> lon2;

    // Convertir a radianes
    double rlat1 = lat1 * PI / 180.0;
    double rlon1 = lon1 * PI / 180.0;
    double rlat2 = lat2 * PI / 180.0;
    double rlon2 = lon2 * PI / 180.0;

    double dlat = rlat2 - rlat1;
    double dlon = rlon2 - rlon1;

    double a = sin(dlat/2)*sin(dlat/2) +
               cos(rlat1)*cos(rlat2)*sin(dlon/2)*sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distancia = R * c;

    cout << fixed << setprecision(2);
    cout << "Distancia entre los puntos: " << distancia << " km" << endl;
}

// ============================================================
// EJERCICIO 13: Haciendo Cambio
// ============================================================
void ejercicio13() {
    cout << "\n=== Ejercicio 13: Haciendo Cambio ===" << endl;

    int centavos;
    cout << "Ingresa la cantidad en centavos: ";
    cin >> centavos;

    int cuartos   = centavos / 25; centavos %= 25;
    int decimos   = centavos / 10; centavos %= 10;
    int nickels   = centavos /  5; centavos %=  5;
    int pennies   = centavos;

    cout << "Monedas de 25c: " << cuartos << endl;
    cout << "Monedas de 10c: " << decimos << endl;
    cout << "Monedas de  5c: " << nickels << endl;
    cout << "Monedas de  1c: " << pennies << endl;
}

// ============================================================
// EJERCICIO 14: Unidades de Altura (pies + pulgadas → cm)
// ============================================================
void ejercicio14() {
    cout << "\n=== Ejercicio 14: Unidades de Altura ===" << endl;

    double pies, pulgadas;
    cout << "Ingresa los pies   : "; cin >> pies;
    cout << "Ingresa las pulgadas: "; cin >> pulgadas;

    // 1 pie = 30.48 cm, 1 pulgada = 2.54 cm
    double totalCm = pies * 30.48 + pulgadas * 2.54;
    cout << fixed << setprecision(2);
    cout << pies << " pie(s) y " << pulgadas << " pulgada(s) = "
         << totalCm << " cm" << endl;
}

// ============================================================
// EJERCICIO 15: Unidades de Distancia (pies → pulgadas, yardas, millas)
// ============================================================
void ejercicio15() {
    cout << "\n=== Ejercicio 15: Unidades de Distancia ===" << endl;

    double pies;
    cout << "Ingresa la distancia en pies: "; cin >> pies;

    double pulgadas = pies * 12.0;
    double yardas   = pies / 3.0;
    double millas   = pies / 5280.0;

    cout << fixed << setprecision(4);
    cout << pies << " pie(s) equivale a:" << endl;
    cout << "  " << pulgadas << " pulgadas" << endl;
    cout << "  " << yardas   << " yardas"   << endl;
    cout << "  " << millas   << " millas"   << endl;
}

// ============================================================
// EJERCICIO 16: Área de Círculo y Volumen de Esfera
// ============================================================
void ejercicio16() {
    cout << "\n=== Ejercicio 16: Area y Volumen ===" << endl;

    const double PI = acos(-1.0);
    double r;
    cout << "Ingresa el radio r: "; cin >> r;

    double area   = PI * r * r;
    double volumen = (4.0 / 3.0) * PI * r * r * r;

    cout << fixed << setprecision(4);
    cout << "Area del circulo (r=" << r << ")   : " << area    << endl;
    cout << "Volumen de la esfera (r=" << r << "): " << volumen << endl;
}

// ============================================================
// EJERCICIO 17: Capacidad de Calor
// ============================================================
void ejercicio17() {
    cout << "\n=== Ejercicio 17: Capacidad de Calor ===" << endl;

    const double C_AGUA  = 4.186;          // J/(g·°C)
    const double PRECIO  = 0.085;          // $/kWh
    const double J_A_KWH = 1.0 / 3600000; // 1 kWh = 3,600,000 J

    double masa, deltaT;
    cout << "Masa del agua (gramos)    : "; cin >> masa;
    cout << "Cambio de temperatura (°C): "; cin >> deltaT;

    double Q   = masa * C_AGUA * deltaT;           // Julios
    double kWh = Q * J_A_KWH;
    double costo = kWh * PRECIO;

    cout << fixed << setprecision(4);
    cout << "Energia necesaria : " << Q      << " J"    << endl;
    cout << "Equivalencia      : " << kWh    << " kWh"  << endl;
    cout << "Costo electrico   : $" << costo << endl;
}

// ============================================================
// EJERCICIO 18: Volumen de un Cilindro
// ============================================================
void ejercicio18() {
    cout << "\n=== Ejercicio 18: Volumen de un Cilindro ===" << endl;

    const double PI = acos(-1.0);
    double radio, altura;
    cout << "Radio del cilindro : "; cin >> radio;
    cout << "Altura del cilindro: "; cin >> altura;

    double volumen = PI * radio * radio * altura;
    cout << fixed << setprecision(1);
    cout << "Volumen del cilindro: " << volumen << endl;
}

// ============================================================
// EJERCICIO 19: Caída Libre
// ============================================================
void ejercicio19() {
    cout << "\n=== Ejercicio 19: Caida Libre ===" << endl;

    const double g = 9.81; // m/s²
    double h;
    cout << "Ingresa la altura (metros): "; cin >> h;

    // v = sqrt(2 * g * h)  (velocidad inicial = 0)
    double velocidad = sqrt(2.0 * g * h);
    cout << fixed << setprecision(2);
    cout << "Velocidad al impactar el suelo: " << velocidad << " m/s" << endl;
}

// ============================================================
// EJERCICIO 20: Ley de los Gases Ideales (n = PV / RT)
// ============================================================
void ejercicio20() {
    cout << "\n=== Ejercicio 20: Ley de los Gases Ideales ===" << endl;

    const double R = 8.314; // J/(mol·K)
    double P, V, T;
    cout << "Presion  P (Pascales): "; cin >> P;
    cout << "Volumen  V (litros)  : "; cin >> V;
    cout << "Temperatura T (Kelvin): "; cin >> T;

    // Convertir litros a m³ (1 L = 0.001 m³)
    double V_m3 = V * 0.001;

    double n = (P * V_m3) / (R * T);
    cout << fixed << setprecision(4);
    cout << "Cantidad de gas: " << n << " moles" << endl;
}

// ============================================================
// MAIN: menú para ejecutar cada ejercicio
// ============================================================
int main() {
    int opcion;
    do {
        cout << "\n===== MENU DE EJERCICIOS =====" << endl;
        cout << " 6  - Impuestos y Propina"             << endl;
        cout << " 7  - Suma de 1 a n"                   << endl;
        cout << " 8  - Widgets y Gizmos"                << endl;
        cout << " 9  - Interes Compuesto"               << endl;
        cout << "10  - Aritmetica"                      << endl;
        cout << "11  - Eficiencia de Combustible"       << endl;
        cout << "12  - Distancia entre dos puntos"      << endl;
        cout << "13  - Haciendo Cambio"                 << endl;
        cout << "14  - Altura (pies+pulgadas a cm)"     << endl;
        cout << "15  - Distancia (pies a otras unidades)"<< endl;
        cout << "16  - Area y Volumen"                  << endl;
        cout << "17  - Capacidad de Calor"              << endl;
        cout << "18  - Volumen de Cilindro"             << endl;
        cout << "19  - Caida Libre"                     << endl;
        cout << "20  - Ley de Gases Ideales"            << endl;
        cout << " 0  - Salir"                           << endl;
        cout << "Selecciona: ";
        cin >> opcion;

        switch (opcion) {
            case  6: ejercicio6();  break;
            case  7: ejercicio7();  break;
            case  8: ejercicio8();  break;
            case  9: ejercicio9();  break;
            case 10: ejercicio10(); break;
            case 11: ejercicio11(); break;
            case 12: ejercicio12(); break;
            case 13: ejercicio13(); break;
            case 14: ejercicio14(); break;
            case 15: ejercicio15(); break;
            case 16: ejercicio16(); break;
            case 17: ejercicio17(); break;
            case 18: ejercicio18(); break;
            case 19: ejercicio19(); break;
            case 20: ejercicio20(); break;
            case  0: cout << "Hasta luego!" << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}