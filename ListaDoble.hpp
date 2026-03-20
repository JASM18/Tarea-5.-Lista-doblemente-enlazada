#ifndef LISTADOBLE_HPP_INCLUDED
#define LISTADOBLE_HPP_INCLUDED

template <typename T>
class ListaDoble {
public:

    ListaDoble();

    ~ListaDoble();

    ListaDoble(const ListaDoble& lista);

    ListaDoble& operator=(const ListaDoble& lista);

    void AgregarInicio(T valor);

    void AgregarFinal(T valor);

    void AgregarEnPos(T valor, int pos);

    void EliminarInicio();

    void EliminarFinal();

    void EliminarEnPos(int pos);

    bool BuscarValor(T valor) const;

    int BuscarPosicion(T valor) const;

    bool EstaVacia() const;

    T ObtenerPrimero() const;

    T ObtenerUltimo() const;

    T ObtenerEnPos(int pos) const;

    void ModificarEnPos(T valor, int pos);

    int ObtenerNumElem() const;

    void Vaciar();

    void Imprimir() const;

    void ImprimirReversa() const;

private:
    int numElem = 0;

    struct Elemento {
        T valor;
        Elemento *anterior, *siguiente;
        Elemento(T v, Elemento *ant = nullptr, Elemento *sig = nullptr);
    };

    Elemento *primero = nullptr;
    Elemento *ultimo = nullptr;
};

#include "ListaDoble.tpp"

#endif // LISTADOBLE_HPP_INCLUDED
