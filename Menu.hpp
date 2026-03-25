#ifndef TAREA5_LISTADOBLE_MENU_HPP
#define TAREA5_LISTADOBLE_MENU_HPP

#include "ListaDoble.hpp"

enum OpsModificar {
    AgregarInicio = 1,
    AgregarFinal,
    AgregarEnPos,
    EliminarInicio,
    EliminarFinal,
    EliminarEnPos,
    EliminarOcurrencias,
    EliminarCondicion,
    EliminarRepetidos,
    Intercambiar,
    TransferirRango,
    TransferirDesde,
    TransferirTodos,
    ModificarValor,
    Vaciar,
    SalirMenu
};

enum OpsConocer {
    BuscarValor = 1,
    BuscarPosicion,
    SiEstaVacia,
    PrimerElemento,
    UltimoElemento,
    CualquierElemento,
    NumeroElementos,
    ImprimirLista,
    ImprimirReversa,
    SalirMenuConocer
};

template <typename T>
void MenuDefinirLista(Lista<T> &lista);

template <typename T>
void MenuConocer(Lista<T> &lista);

template <typename T>
void MenuOperator(Lista<T> &lista);

#include "Menu.tpp"

#endif //TAREA5_LISTADOBLE_MENU_HPP
