#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;


struct Proceso {
    string id;
    int llegada;
    int servicio;
    int comienzo;
    int finalizacion;
    int espera;
    int estancia;
    double estanciaNormalizada;
};

int main() {
    int numProcesos;

    cout << "==========================================================" << endl;
    cout << "     SIMULACION DE PLANIFICACION DE PROCESOS - FCFS       " << endl;
    cout << "==========================================================" << endl;

    do {
        cout << "Ingrese el numero de procesos (entre 3 y 5): ";
        cin >> numProcesos;
        if (numProcesos < 3 || numProcesos > 5) {
            cout << "[-] Cantidad no valida. Debe estar entre 3 y 5.\n";
        }
    } while (numProcesos < 3 || numProcesos > 5);

    vector<Proceso> procesos(numProcesos);

    // Lectura de datos según el orden de entrada
    for (int i = 0; i < numProcesos; ++i) {
        cout << "\n--- Proceso " << (i + 1) << " ---" << endl;
        cout << "Identificador (ID): ";
        cin >> procesos[i].id;
        
        do {
            cout << "Tiempo de llegada (TL >= 0): ";
            cin >> procesos[i].llegada;
        } while (procesos[i].llegada < 0);

        do {
            cout << "Tiempo de servicio (Ts > 0): ";
            cin >> procesos[i].servicio;
        } while (procesos[i].servicio <= 0);
    }

    sort(procesos.begin(), procesos.end(), [](const Proceso &a, const Proceso &b) {
        return a.llegada < b.llegada;
    });

    int tiempoActual = 0;
    double sumaEspera = 0.0;
    double sumaEstancia = 0.0;
    double sumaEstanciaNorm = 0.0;

    for (int i = 0; i < numProcesos; ++i) {
        if (tiempoActual < procesos[i].llegada) {
            tiempoActual = procesos[i].llegada;
        }

        procesos[i].comienzo = tiempoActual;
        procesos[i].finalizacion = procesos[i].comienzo + procesos[i].servicio;
        procesos[i].espera = procesos[i].comienzo - procesos[i].llegada;
        procesos[i].estancia = procesos[i].finalizacion - procesos[i].llegada;
        procesos[i].estanciaNormalizada = static_cast<double>(procesos[i].estancia) / procesos[i].servicio;

        tiempoActual = procesos[i].finalizacion;

        sumaEspera += procesos[i].espera;
        sumaEstancia += procesos[i].estancia;
        sumaEstanciaNorm += procesos[i].estanciaNormalizada;
    }

    cout << "\n\n========================================================================================\n";
    cout << "                                  TABLA DE RESULTADOS                                   \n";
    cout << "========================================================================================\n";
    cout << left << setw(10) << "Proceso" 
         << setw(8)  << "TL" 
         << setw(8)  << "Ts" 
         << setw(8)  << "TC" 
         << setw(8)  << "TF" 
         << setw(8)  << "TE" 
         << setw(8)  << "Tr" 
         << setw(10) << "Tr/Ts" << endl;
    cout << "----------------------------------------------------------------------------------------\n";

    for (const auto &p : procesos) {
        cout << left << setw(10) << p.id 
             << setw(8)  << p.llegada 
             << setw(8)  << p.servicio 
             << setw(8)  << p.comienzo 
             << setw(8)  << p.finalizacion 
             << setw(8)  << p.espera 
             << setw(8)  << p.estancia 
             << fixed << setprecision(2) << setw(10) << p.estanciaNormalizada << endl;
    }

    cout << "----------------------------------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Tiempo de Espera Promedio   (TE) : " << (sumaEspera / numProcesos) << endl;
    cout << "Tiempo de Estancia Promedio (Tr) : " << (sumaEstancia / numProcesos) << endl;
    cout << "Estancia Normalizada Promedio    : " << (sumaEstanciaNorm / numProcesos) << endl;
    cout << "========================================================================================\n";

    return 0;
}
