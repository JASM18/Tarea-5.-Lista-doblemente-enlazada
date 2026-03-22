#include <iostream>

#include "ListaDoble.hpp"

using namespace std;

int main()
{
    cout << "Prueba" << endl;

    try{
        ListaDoble<int> listita;

        cout << "Agregando elementos..." << endl;

        for (int i = 0 ; i < 10 ; ++i) {
            listita.AgregarFinal(i);
            cout << listita << endl;
        }

        cout << "Modificando elementos con operator[]..." << endl;
        listita[2] = 67;
        cout << listita << endl;

    }catch(const char* mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(const exception &error){
        cerr << "Error: " << error.what();
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }
    system("pause");
    return 0;
}
