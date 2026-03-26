/**
* \file Menu.tpp
* \brief Este archivo contiene la implementaci&oacute;n de los submen&uacute;s y operaciones de prueba de la lista.
* \author S&aacute;nchez Montoy, Jes&uacute;s Axel
* \author Portugal Arreola, Marian Bethsab&eacute;
* \date 25/03/2026
*/

#include <iostream>
#include <exception>

#include "Menu.hpp"
#include "CapturaSegura.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

//Para poder usar la funcion EliminarCondicion
template <typename T>
bool CondicionPrueba(T valor)
{
    return valor > 10;
}

//**************************

template <typename T>
void MenuDefinirLista(Lista<T> &lista)
{
    int opcion =-1;
    int pos = 0;
    int inicio, fin;
    T valor;
    Lista<T> listaReceptora;

    do {

        system("CLS");

        cout << "==============================" << endl;
        cout << "DEFINIENDO LA LISTA..." << endl;
        cout << "==============================" << endl << endl;

        cout << "Lista: " << lista << endl << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << AgregarInicio << ") Agregar un elemento al inicio." << endl;
        cout << "\t" << AgregarFinal << ") Agregar un elemento al final." << endl;
        cout << "\t" << AgregarEnPos << ") Agregar un elemento en una posici\242n." << endl;
        cout << "\t" << EliminarInicio << ") Eliminar el primer elemento." << endl;
        cout << "\t" << EliminarFinal << ") Eliminar el \243ltimo elemento." << endl;
        cout << "\t" << EliminarEnPos << ") Eliminar un elemento en una posici\242n." << endl;
        cout << "\t" << EliminarOcurrencias << ") Eliminar todas las ocurrencias de un valor." << endl;
        cout << "\t" << EliminarCondicion << ") Eliminar valores seg\243n una funci\242n de condici\242n. " << endl;
        cout << "\t" << EliminarRepetidos << ") Eliminar todos los valores repetidos." << endl;
        cout << "\t" << Intercambiar << ") Intercambiar una lista con otra." << endl;
        cout << "\t" << TransferirRango << ") Transferir elementos a otra lista siguiendo un rango. " << endl;
        cout << "\t" << TransferirDesde << ") Transferir los elementos a otra lista desde cierta posici\242n." << endl;
        cout << "\t" << TransferirTodos << ") Transferir todos los elementos a otra lista." << endl;
        cout << "\t" << ModificarValor << ") Modificar el valor de un elemento en una posici\242n." << endl;
        cout << "\t" << Vaciar << ") Vaciar la lista." << endl;
        cout << "\t" << SalirMenu << ") Regresar al men\243 principal." << endl;

        do{
            CapturarNumero(opcion, "Elige una opci\242n: ");
        }while(opcion > SalirMenu || opcion < AgregarInicio);

        cout << "\n- - - - -" << endl << endl;

        if(opcion == SalirMenu) continue;

        try {

            switch (opcion) {
                case AgregarInicio:
                    CapturarNumero(valor, "Valor a agregar al inicio: ");
                    lista.AgregarInicio(valor);
                    cout << "[\220XITO] Valor agregado al inicio: " << valor << endl;
                break;

                case AgregarFinal:
                    CapturarNumero(valor, "Valor a agregar al final: ");
                    lista.AgregarFinal(valor);
                    cout << "[\220XITO] Valor agregado al final: " << valor << endl;
                break;

                case AgregarEnPos:
                    CapturarNumero(valor, "Valor a agregar: ");
                    CapturarNumero(pos, "Posici\242n donde agregar: ");
                    lista.AgregarEnPos(valor, pos);
                    cout << "[\220XITO] Valor agregado: " << valor << " en posici\242n " << pos << endl;
                break;

                case EliminarInicio:
                    valor = lista.ObtenerPrimero();
                    lista.EliminarInicio();
                    cout << "[\220XITO] Valor eliminado del inicio: " << valor << endl;
                break;

                case EliminarFinal:
                    valor = lista.ObtenerUltimo();
                    lista.EliminarFinal();
                    cout << "[\220XITO] Valor eliminado del final: " << valor << endl;
                break;

                case EliminarEnPos:
                    CapturarNumero(pos, "Posici\242n a eliminar: ");
                    valor = lista.ObtenerEnPos(pos);
                    lista.EliminarEnPos(pos);
                    cout << "[\220XITO] Valor eliminado: " << valor << " en posici\242n " << pos << endl;

                break;

                case EliminarOcurrencias:

                    CapturarNumero(valor, "Valor a eliminar: ");
                    lista.EliminarOcurrencias(valor);
                    cout << "[\220XITO] Valor eliminado: " << valor << " en todas las posiciones. " << endl;

                break;

                case EliminarCondicion:

                    cout << "Para probar este m\202todo, se usar\240 la condici\242n de retornar solo valores mayores a 10." << endl;
                    lista.EliminarCondicion(CondicionPrueba<T>);
                    cout << "[\220XITO] Elementos eliminados seg\243n la condici\242n." << endl;

                break;

                case EliminarRepetidos:

                    lista.EliminarRepetidos();
                    cout << "[\220XITO] Todos los elementos repetidos fueron eliminados." << endl;

                break;

                case Intercambiar: {
                    Lista<T> listaPrueba;

                    listaPrueba.AgregarFinal(99);
                    listaPrueba.AgregarFinal(100);
                    listaPrueba.AgregarFinal(101);

                    cout << "Lista actual: " << lista << endl;
                    cout << "Lista de prueba: " << listaPrueba << endl;

                    lista.Intercambiar(listaPrueba);

                    cout << "\n[\220XITO] Las listas fueron intercambiadas." << endl;
                }
                break;

                case TransferirRango:

                    CapturarNumero(inicio, "\326ndice de inicio del corte: ");
                    CapturarNumero(fin, "\326ndice de fin del corte: ");

                    lista.TransferirEnRango(listaReceptora, inicio, fin);

                    cout << "\n[\220XITO] Elementos transferidos." << endl;
                    cout << "Lista con los datos extra\241dos: " << listaReceptora << endl;

                break;

                case TransferirDesde:

                    CapturarNumero(inicio, "\326ndice desde donde empezar a cortar: ");

                    lista.TransferirDesde(listaReceptora, inicio);

                    cout << "\n[\220XITO] Elementos transferidos hasta el final." << endl;

                break;

                case TransferirTodos:

                    lista.TransferirTodos(listaReceptora);

                    cout << "\n[\220XITO] Toda la lista fue transferida." << endl;
                    cout << "La lista receptora se llen\242 con: " << listaReceptora << endl;

                break;

                case ModificarValor:
                    CapturarNumero(pos, "Posici\242n a modificar: ");
                    CapturarNumero(valor, "Nuevo valor: ");

                    lista.ModificarEnPos(valor, pos);

                    cout << "[\220XITO] Valor modificado: " << valor << " en posici\242n " << pos << endl;
                break;

                case Vaciar:
                    lista.Vaciar();
                    cout << "[\220XITO] Lista vaciada" << endl;
                break;
            }

        }catch(const char* mensaje){
            cerr << "Error: " << mensaje << endl;
        }catch(const std::exception &error){
            cerr << "Error: " << error.what() << endl;
        }catch(...){
            cerr << "El programa tuvo un error inesperado." << endl;
        }

        cout << endl;
        system("pause");
        system("CLS");
    }while(opcion != SalirMenu);

}

template<typename T>
void MenuConocer(Lista<T> &lista)
{
    int opcion = -1;
    int pos = 0;
    T valor;

    do {
        system("CLS");

        cout << "==============================" << endl;
        cout << "CONOCIENDO DATOS DE LA LISTA..." << endl;
        cout << "==============================" << endl << endl;

        cout << "Lista: " << lista << endl << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << BuscarValor << ") Buscar un valor en la lista." << endl;
        cout << "\t" << BuscarPosicion << ") Buscar la posici\242n de un valor en la lista (primera ocurrencia)." << endl;
        cout << "\t" << SiEstaVacia << ") Conocer si la lista está vac\241a." << endl;
        cout << "\t" << PrimerElemento << ") Obtener el primer elemento de la lista." << endl;
        cout << "\t" << UltimoElemento << ") Obtener el \243ltimo elemento de la lisa." << endl;
        cout << "\t" << CualquierElemento << ") Obtener el elemento de la lista en cierta posici\242n (o \241ndice)" << endl;
        cout << "\t" << NumeroElementos << ") Obtener el n\243mero de elementos que contiene la lista." << endl;
        cout << "\t" << ImprimirLista << ") Imprimir la lista." << endl;
        cout << "\t" << ImprimirReversa << ") Imprimir la lista en reversa." << endl;
        cout << "\t" << SalirMenuConocer << ") Regresar al men\243 principal." << endl;

        do{
            CapturarNumero(opcion, "Elige una opci\242n: ");
        }while(opcion > SalirMenuConocer || opcion < BuscarValor);

        cout << "\n- - - - -" << endl << endl;

        if(opcion == SalirMenuConocer) continue;

        try {

            switch (opcion){
                case BuscarValor:
                    cout << "Valor a buscar: ";
                    cin >> valor;

                    cout << endl;
                    cout << "El valor " << valor << " est\240 en la lista: " << (lista.BuscarValor(valor) ? "True" : "False") << endl;

                break;

                case BuscarPosicion:

                    cout << "Valor a buscar para obtener su posici\242n: ";
                    cin >> valor;

                    pos = lista.BuscarPosicion(valor);

                    cout << endl;
                    if(pos != -1){
                        cout << "El valor " << valor << " se encuentra en la posici\242n: " << pos << endl;
                    }else{
                        cout << "El valor " << valor << " no se encuentra en la lista." << endl;
                    }

                break;

                case SiEstaVacia:
                    cout << "La lista " << (lista.EstaVacia() ? "est\240 vac\241a." : "no est\240 vac\241a.") << endl;
                break;

                case PrimerElemento:
                        cout << "El primer elemento de la lista es: " << lista.ObtenerPrimero() << endl;
                break;

                case UltimoElemento:
                    cout << "El \243ltimo elemento de la lista es: " << lista.ObtenerUltimo() << endl;
                break;

                case CualquierElemento:
                    CapturarNumero(pos, "Posici\242n del elemento a obtener: ");
                    cout << "El elemento en la posici\242n " << pos << " es: " << lista.ObtenerEnPos(pos) << endl;
                break;

                case NumeroElementos:
                    cout << "La lista contiene " << lista.ObtenerNumElem() << " elementos." << endl;
                break;

                case ImprimirLista:
                    cout << "La lista es: " << lista << endl;
                break;

                case ImprimirReversa:
                    cout << "La lista en reversa es: ";
                        lista.ImprimirReversa();
                    cout << endl;
                break;
            }

        }catch(const char* mensaje){
            cerr << "Error: " << mensaje << endl;
        }catch(const std::exception &error){
            cerr << "Error: " << error.what() << endl;
        }catch(...){
            cerr << "El programa tuvo un error inesperado." << endl;
        }

        cout << endl;
        system("pause");
        system("CLS");
    }while(opcion != SalirMenuConocer);
}

template <typename T>
void MenuOperator(Lista<T> &lista)
{
    system("CLS");

    cout << "==============================" << endl;
    cout << "Probando la sobrecarga operator[]" << endl;
    cout << "==============================" << endl << endl;

    cout << "-> Se va a definir una nueva lista para ponerlo a prueba." << endl;

    Lista<int> listita;

    for (int i = 0 ; i < 10 ; ++i) {
        listita.AgregarFinal(i);
    }

    cout << "\nLa lista es: " << listita << endl;

    cout << "\n-> Se va intercambiar el " << listita[5] << " por un 99." << endl;

    listita[5] = 99;

    cout << "listita[5]: " << listita[5] << endl;

    cout << "\nLa lista ahora es: " << listita << endl;

}
