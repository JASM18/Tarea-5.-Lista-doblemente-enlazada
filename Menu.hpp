/**
* \file Menu.hpp
* \brief Este archivo contiene las definiciones de los men&uacute;s interactivos para modificar y conocer la clase Lista.
* \author S&aacute;nchez Montoy, Jes&uacute;s Axel
* \author Portugal Arreola, Marian Bethsab&eacute;
* \date 25/03/2026
* \code{.cpp}
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
* \endcode
*/

#ifndef TAREA5_LISTADOBLE_MENU_HPP
#define TAREA5_LISTADOBLE_MENU_HPP

#include "ListaDoble.hpp"

/**
* \brief Opciones del men&uacute; de modificaciones.
*/
enum OpsModificar {
    AgregarInicio = 1,          ///< Agregar un elemento al inicio de la lista.
    AgregarFinal,               ///< Agregar un elemento al final de la lista.
    AgregarEnPos,               ///< Agregar un elemento en el &iacute;ndice indicado.
    EliminarInicio,             ///< Eliminar el elemento inicial.
    EliminarFinal,              ///< Eliminar el &uacute;ltimo elemeto.
    EliminarEnPos,              ///< Eliminar el elemento de la posici&oacute;n indicada.
    EliminarOcurrencias,        ///< Eliminar todas las copias de un valor.
    EliminarCondicion,          ///< Eliminar elementos bas&aacute;ndose en una funci&oacute;n de condici&oacute;n.
    EliminarRepetidos,          ///< Dejar solo una aparici&oacute;n de cada valor.
    Intercambiar,               ///< Intercambiar los datos de la lista actual con otra de prueba.
    TransferirRango,            ///< Mover los elementos de un &iacute;ndice a otro hacia una lista nueva.
    TransferirDesde,            ///< Mover los elementos desde un punto en adelante hacia otra lista.
    TransferirTodos,            ///< Mover toda la lista a otra lista receptora.
    ModificarValor,             ///< Editar el valor de un elemento con la sobrecarga del corchete.
    Vaciar,                     ///< Destruir todos los elementos en memoria.
    SalirMenu                   ///< Salir del submen&uacute;.
};

/**
* \brief Opciones del men&uacute; de conocer.
*/
enum OpsConocer {
    BuscarValor = 1,            ///< Verificar si un dato existe.
    BuscarPosicion,             ///< Regresar la posici&oacute;n en el que se ubica un dato.
    SiEstaVacia,                ///< Comprobar si la lista contiene o no elementos.
    PrimerElemento,             ///< Mostrar el contenido del primer elemento.
    UltimoElemento,             ///< Mostrar el contenido del &uacute;ltimo elemento.
    CualquierElemento,          ///< Mostrar un dato basado en un &iacute;ndice espec&iacute;fico.
    NumeroElementos,            ///< Regresar la cantidad de elementos.
    ImprimirLista,              ///< Imprimir la lista de izquierda a derecha.
    ImprimirReversa,            ///< Imprimir la lista de derecha a izquierda.
    SalirMenuConocer            ///< Salir del submen&uacute;.
};

/** \brief Funci&oacute;n para el men&uacute; con operaciones que modifican la lista.
* \tparam T Tipo de dato con el que opera la lista.
* \param lista Referencia a la lista que se modificar&aacute;.
* \return void
*/
template <typename T>
void MenuDefinirLista(Lista<T> &lista);

/** \brief Funci&oacute;n para el men&uacute; con operaciones para obtener datos y valores sin alterar la lista.
* \tparam T Tipo de dato con el que opera la lista.
* \param lista Referencia constante a la lista consultada.
* \return void
*/
template <typename T>
void MenuConocer(Lista<T> &lista);

/** \brief Funci&oacute;n de prueba para demostrar el funcionamiento del operador sobrecargado de sub&iacute;ndices (operator[]).
* \tparam T Tipo de dato con el que opera la lista.
* \param lista Referencia a la lista que ser&aacute; modificada.
* \return void
*/
template <typename T>
void MenuOperator(Lista<T> &lista);

#include "Menu.tpp"

#endif //TAREA5_LISTADOBLE_MENU_HPP
