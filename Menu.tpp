#include <iostream>
#include <exception>

#include "Menu.hpp"
#include "CapturaSegura.hpp"

using std::cout;
using std::endl;
using std::cerr;

enum OpcionesModificar {
    AgregarInicio = 1,
    AgregarFinal,
    AgregarEnPos,
    EliminarInicio,
    EliminarFinal,
    EliminarEnPos,
    ModificarValor,
    Vaciar,
    SalirMenu
};

template <typename T>
void MenuDefinirLista(Lista<T> &lista)
{
    int opcion =-1;
    int pos = 0;
    T valor;

    do {
        system("CLS");

        cout << "==============================" << endl;
        cout << "DEFINIENDO LA LISTA..." << endl;
        cout << "==============================" << endl << endl;

        cout << "Lista: " << lista << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << AgregarInicio << ") Agregar un elemento al inicio." << endl;
        cout << "\t" << AgregarFinal << ") Agregar un elemento al final." << endl;
        cout << "\t" << AgregarEnPos << ") Agregar un elemento en una posici\242n." << endl;
        cout << "\t" << EliminarInicio << ") Eliminar el primer elemento." << endl;
        cout << "\t" << EliminarFinal << ") Eliminar el \250ltimo elemento." << endl;
        cout << "\t" << EliminarEnPos << ") Eliminar un elemento en una posici\242n." << endl;
        cout << "\t" << ModificarValor << ") Modificar el valor de un elemento en una posici\242n." << endl;
        cout << "\t" << Vaciar << ") Vaciar la lista." << endl;
        cout << "\t" << SalirMenu << ") Regresar al men\243 principal." << endl;

        do{
            CapturarNumero(opcion, "Elige una opci\242n: ");
        }while(opcion > SalirMenu || opcion < AgregarInicio);

        cout << endl;

        if(opcion == SalirMenu) continue;

        try {

            switch (opcion) {
                case AgregarInicio:
                    CapturarNumero(valor, "Valor a agregar al inicio: ");
                    lista.AgregarInicio(valor);
                    cout << "[EXITO] Valor agregado al inicio: " << valor << endl;
                break;

                case AgregarFinal:
                    CapturarNumero(valor, "Valor a agregar al final: ");
                    lista.AgregarFinal(valor);
                    cout << "[EXITO] Valor agregado al final: " << valor << endl;
                break;

                case AgregarEnPos:
                    CapturarNumero(valor, "Valor a agregar: ");
                    CapturarNumero(pos, "Posici\242n donde agregar: ");
                    lista.AgregarEnPos(valor, pos);
                    cout << "[EXITO] Valor agregado: " << valor << " en posici\242n " << pos << endl;
                break;

                case EliminarInicio:
                    valor = lista.ObtenerPrimero();
                    lista.EliminarInicio();
                    cout << "[EXITO] Valor eliminado del inicio: " << valor << endl;
                break;

                case EliminarFinal:
                    valor = lista.ObtenerUltimo();
                    lista.EliminarFinal();
                    cout << "[EXITO] Valor eliminado del final: " << valor << endl;
                break;

                case EliminarEnPos:
                    CapturarNumero(pos, "Posici\242n a eliminar: ");
                    valor = lista.ObtenerEnPos(pos);
                    lista.EliminarEnPos(pos);
                    cout << "[EXITO] Valor eliminado: " << valor << " en posici\242n " << pos << endl;

                break;

                case ModificarValor:
                    CapturarNumero(pos, "Posici\242n a modificar: ");
                    CapturarNumero(valor, "Nuevo valor: ");

                    lista.ModificarEnPos(valor, pos);

                    cout << "[EXITO] Valor modificado: " << valor << " en posici\242n " << pos << endl;
                break;

                case Vaciar:
                    lista.Vaciar();
                    cout << "[EXITO] Lista vaciada" << endl;
                break;
            }

        }catch(const char* mensaje){
            cerr << "Error: " << mensaje << endl;
        }catch(const std::exception &error){
            cerr << "Error: " << error.what();
        }catch(...){
            cerr << "El programa tuvo un error inesperado." << endl;
        }

        system("pause");
        system("CLS");
    }while(opcion != SalirMenu);

}