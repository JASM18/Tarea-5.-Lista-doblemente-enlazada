#ifndef LISTADOBLE_HPP_INCLUDED
#define LISTADOBLE_HPP_INCLUDED

template <typename T>
class ListaDoble{
public:
    void AgregarEnPos(T valor, int pos);
    void EliminarDelFinal();
    bool EstaVacia();
    void AgregarAlInicio(T valor);
    void AgregarAlFinal(T valor);

private:
    int numElem = 0;
    Elemento *primero = nullptr;
    Elemento *ultimo = nullptr;

    struct Elemento {
        T valor;
        Elemento *anterior, *siguiente;
        Elemento(T v, Elemento *ant = nullptr, *sig = nullptr);
    };
};

#include "ListaDoble.tpp"

#endif // LISTADOBLE_HPP_INCLUDED
