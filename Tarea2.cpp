#include <iostream>
using namespace std;

void ordenar(int* puntos, int tamanio){
    for(int i = 0; i < tamanio - 1; i++){
        if(*(puntos + i) > *(puntos + i + 1)){
            int temporal = *(puntos + i);
            *(puntos + i) = *(puntos + i + 1);
            *(puntos + i + 1) = temporal;
            i = -1;
        }
    } 
}

void busquedaBinaria(int* puntos, int tamanio, int valor){
    int inicio = 0;
    int fin = tamanio;
    bool encontrado = false;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (*(puntos + medio) == valor) {
            cout << "Punteo encontrado en la posicion: " << medio +1<< endl;
            encontrado = true;
            break;
        } else if (*(puntos + medio) < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    if (!encontrado) {
        cout << "Punteo no encontrado" << endl;
    }
}


void actualizar(int* puntos, int tamanio, int posicion, int punteoActualizado){
    if(posicion >= 0 && posicion < tamanio){
        *(puntos + posicion) = punteoActualizado;
        cout << "Punteo actualizado correctamente." << endl;
    } else {
        cout << "Posicion invalida." << endl;
    }
}

void imprimir(int* puntos, int tamanio){
    cout << "Puntos actuales: ";
    for(int i = 0; i < tamanio; i++){
        cout << *(puntos + i) << " ";
    }
    cout << endl;
}

int main(){
    const int TAMANIO_ARREGLO = 12;
    int puntos[TAMANIO_ARREGLO];

    for(int i = 0; i < TAMANIO_ARREGLO; i++){
        cout << "Inserte punteo: ";
        cin >> *(puntos + i);
    }

    int opcion;
    do{
        cout << "\nMenu de opciones:\n";
        cout << "1. Ordenar puntos...\n";
        cout << "2. Buscar punteo...\n";
        cout << "3. Actualizar punteo...\n";
        cout << "4. Imprimir arreglo...\n";
        cout << "5. Salir...\n";
        cout << "Ingresar opcion deseada: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                ordenar(puntos, TAMANIO_ARREGLO);
                cout << "Puntos ordenados correctamente." << endl;
                imprimir(puntos, TAMANIO_ARREGLO);
                break;
            case 2:
                int punteo;
                cout << "Ingrese el punteo que desea buscar: ";
                cin >> punteo;
                busquedaBinaria(puntos, TAMANIO_ARREGLO, punteo);
                break;
            case 3:
                int posicion, punteoActualizado;
                cout << "Ingrese la posicion del punteo que desea actualizar (1 - " << TAMANIO_ARREGLO << "): ";
                cin >> posicion;
                cout << "Ingrese punteo nuevo: ";
                cin >> punteoActualizado;
                actualizar(puntos, TAMANIO_ARREGLO, posicion - 1, punteoActualizado);
                imprimir(puntos, TAMANIO_ARREGLO);
                break;
            case 4:
                imprimir(puntos, TAMANIO_ARREGLO);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "INGRESAR OPCION VALIDA" << endl;
        }

    } while(opcion != 5);

    return 0;
}



// CASO DE USO DE REFERENCIA

#include <iostream>
using namespace std;

void dividirEnDos(int &numero) {
    numero = numero / 2;
}

int main() {
    int x = 5;

    cout << "Valor antes de dividir: " << x << endl;

    dividirEnDos(x); 

    cout << "Valor después de dividir: " << x << endl;

    return 0;
}
