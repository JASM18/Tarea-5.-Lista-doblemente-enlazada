#include <iostream>

#include "ListaDoble.hpp"

using namespace std;

int main()
{

    ListaDoble<int> miLista;

    miLista.AgregarInicio(5); // <-- Aquí detonas la bomba

    return 0;
}
