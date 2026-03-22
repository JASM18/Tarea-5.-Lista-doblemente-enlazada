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

    T &operator[](int pos); //devuelve una referencia, no debe ser constante

    T operator[](int pos) const; //devuelve valor, debe ser constante


    /**
     * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando se intenta acceder o extraer de una cola vac&iacute;a.
     */
    class ListaVacia : public std::exception {
    public:
        /** \brief Constructor por default de la excepci&oacute;n ColaVacia.
         */
        ListaVacia() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una lista vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando ocurren fallos de reserva de memoria.
    */
    class ListaNoMemoria : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaNoMemoria() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando no haya memoria disponible.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando el cliente intenta acceder a indices no disponibles
    */
    class ListaIndice : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaIndice() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando el cliente intente acceder a indices no disponibles.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

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
