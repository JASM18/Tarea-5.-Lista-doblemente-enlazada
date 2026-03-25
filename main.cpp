#include <iostream>

#include "ListaDoble.hpp"
#include "Menu.hpp"
#include  "CapturaSegura.hpp"

using namespace std;

enum Opciones_principales {
    MODIFICARLISTA = 1,
    CONOCER,
    OPERATOR,
    SALIR,
};

int main()
{
    int opcion = -1;
    Lista<int> lista;

    do{
        cout << "==================================" << endl;
        cout << "Tarea 5. Lista doblemente enlazada" << endl;
        cout << "==================================" << endl << endl;

        cout << "Lista: " << lista << endl << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << MODIFICARLISTA << ") Modificar una lista. (Agregar, eliminar, modificar, transferir, vaciar)" << endl;
        cout << "\t" << CONOCER << ") Conocer datos de la lista (Buscar, obtener, imprimir)" << endl;
        cout << "\t" << OPERATOR << ") Probar la sobrecarga operator[]" << endl;
        cout << "\t" << SALIR << ") Salir del programa." << endl;

        do{
            CapturarNumero(opcion, "Elige una opci\242n: ");
        }while(opcion > SALIR || opcion < MODIFICARLISTA);

        if(opcion == SALIR) continue;

        try{
            switch(opcion){

                case MODIFICARLISTA :
                    MenuDefinirLista(lista);
                break;

                case CONOCER :
                    MenuConocer(lista);
                break;

                case OPERATOR:
                    MenuOperator(lista);
                break;
            }
        }catch(const char* mensaje){
            cerr << "Error: " << mensaje << endl;
        }catch(const exception &error){
            cerr << "Error: " << error.what() << endl;
        }catch(...){
            cerr << "El programa tuvo un error inesperado." << endl;
        }

        system ("pause");
        system("CLS");
    }while(opcion != SALIR);

    cout << "\nEl programa ha terminado." << endl;

    system("pause");
    return 0;
}
