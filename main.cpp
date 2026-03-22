#include <iostream>

#include "ListaDoble.hpp"

using namespace std;

int main()
{
    cout << "Prueba" << endl;

    ListaDoble<int> listita;

    listita.AgregarInicio(1);
    listita.Imprimir();
    cout << endl;
    listita.AgregarInicio(2);
    listita.Imprimir();
    cout << endl;
    listita.AgregarInicio(3);
    listita.Imprimir();
    cout << endl;
    listita.AgregarEnPos(5, 2);
    listita.Imprimir();
    cout << endl << "busqueda\n6: " << endl;
    cout << listita.BuscarValor(6);
    cout << endl << "busqueda\n3: " << endl;
    cout << listita.BuscarValor(3);
    cout << "ELIMINANDO EN POS 0" << endl;
    listita.EliminarEnPos(0);
    listita.Imprimir();

    return 0;
}
