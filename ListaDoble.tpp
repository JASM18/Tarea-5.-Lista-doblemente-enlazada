#include <iostream>

//***********************************
// CONSTRUCTORES
//***********************************

template <typename T>
ListaDoble<T>::ListaDoble()
{
    numElem = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template <typename T>
ListaDoble<T>::~ListaDoble()
{
    Vaciar();
}

template <typename T>
ListaDoble<T>::ListaDoble(const ListaDoble& lista)
{
    numElem = 0;
    primero = nullptr;
    ultimo = nullptr;
    *this = lista;
}

template <typename T>
ListaDoble<T>& ListaDoble<T>::operator=(const ListaDoble& lista)
{

}

template <typename T>
void ListaDoble<T>::AgregarInicio(T valor)
{
    try{
        Elemento *nuevo = new Elemento(valor);

        if(EstaVacia()){
            primero = nuevo;
            ultimo = nuevo;
        }else{
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;
        }

        ++numElem;
    }catch(const std::bad_alloc&){
        throw ListaNoMemoria();
    }
}

template <typename T>
void ListaDoble<T>::AgregarFinal(T valor)
{
    try{
        Elemento *nuevo = new Elemento(valor);

        if(EstaVacia()){
            primero = nuevo;
            ultimo = nuevo;
        }else{
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;

            ultimo = nuevo;
        }

        numElem++;

    }catch(const std::bad_alloc&){
        throw ListaNoMemoria();
    }
}

template <typename T>
void ListaDoble<T>::AgregarEnPos(T valor, int pos)
{
    if(pos < 0 || pos > numElem) throw ListaIndice();

    if(pos == 0){
        AgregarInicio(valor);

    }else if (pos == numElem){
        AgregarFinal(valor);

    }else{
        Elemento *visitado;
        if (pos > numElem/2){
            visitado = ultimo;

            for (int i = numElem-1; i > pos; i--){
                visitado = visitado->anterior;
            }

        }else{
            visitado = primero;

            for (int i = 0; i < pos; i++){
                visitado = visitado->siguiente;
            }
        }

        try{
            Elemento *nuevo = new Elemento(valor, visitado->anterior, visitado);
            visitado->anterior->siguiente = nuevo;
            visitado->anterior = nuevo;
            numElem++;
        }catch(const std::bad_alloc&){
            throw ListaNoMemoria();
        }
    }
}

template <typename T>
void ListaDoble<T>::EliminarInicio()
{
    if(EstaVacia()){
        throw ListaVacia();
    }

    Elemento *porBorrar = primero;

    if(numElem == 1){
        primero = nullptr;
        ultimo = nullptr;

    }else{
        primero = primero->siguiente;
        primero->anterior = nullptr;
    }

    delete porBorrar;
    --numElem;
}

template <typename T>
void ListaDoble<T>::EliminarFinal()
{
    if(EstaVacia()){
        throw ListaVacia();
    }

    Elemento *porBorrar = ultimo;

    if(numElem == 1){
        primero = nullptr;
        ultimo = nullptr;

    }else{
        ultimo = ultimo->anterior;
        ultimo->siguiente = nullptr;
    }

    delete porBorrar;
    --numElem;
}

template <typename T>
void ListaDoble<T>::EliminarEnPos(int pos)
{
    if (pos < 0 || pos >= numElem) throw ListaIndice();

    if (EstaVacia()) throw ListaVacia();

    if (pos == 0){
        EliminarInicio();
        return;
    }

    if (pos == numElem-1){
        EliminarFinal();
        return;
    }

    Elemento *visitado = primero->siguiente;

    for (int i = 1; i < pos; i++){
        visitado = visitado->siguiente;
    }

    visitado->anterior->siguiente = visitado->siguiente;
    visitado->siguiente->anterior = visitado->anterior;

    numElem--;

    delete visitado;
}


template <typename T>
bool ListaDoble<T>::BuscarValor(T valor) const
{
    Elemento *busqueda = primero;

    for (int i = 0; i < numElem; i++){
        if (busqueda->valor == valor){
            return true;
        }

        busqueda = busqueda->siguiente;
    }

    return false;
}

template <typename T>
int ListaDoble<T>::BuscarPosicion(T valor) const
{
    Elemento *visitado = primero;

    for (int i = 0; i < numElem; i++){
        if (visitado->valor == valor){
            return i;
        }
        visitado = visitado->siguiente;
    }
    return -1;
}

template <typename T>
bool ListaDoble<T>::EstaVacia() const
{
    if (numElem == 0){
        return true;
    }
    return false;
}

template <typename T>
T ListaDoble<T>::ObtenerPrimero() const
{

}

template <typename T>
T ListaDoble<T>::ObtenerUltimo() const
{

}

template <typename T>
T ListaDoble<T>::ObtenerEnPos(int pos) const
{

}

template <typename T>
void ListaDoble<T>::ModificarEnPos(T valor, int pos)
{

}

template <typename T>
int ListaDoble<T>::ObtenerNumElem() const
{

}

template <typename T>
void ListaDoble<T>::Vaciar()
{
    while (!EstaVacia()){
        EliminarInicio();
    }
}

template <typename T>
void ListaDoble<T>::Imprimir() const
{
    if(EstaVacia()){
        std::cout << "[ ]" << std::endl;
        return;
    }

    Elemento *visitado = primero;
    std::cout << "[ ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->siguiente;
    }

    if(!EstaVacia()) std::cout << "\b\b ]";
}

template <typename T>
void ListaDoble<T>::ImprimirReversa() const
{

}

//***********************************
// Constructor de Elemento
//***********************************

template <typename T>
ListaDoble<T>::Elemento::Elemento(T v, Elemento *ant /*=nullptr*/, Elemento *sig /*=nullptr*/) : valor(v), anterior(ant), siguiente(sig) {}

//***********************************
// Implementación de la clase ListaVacia
//***********************************

template <typename T>
ListaDoble<T>::ListaVacia::ListaVacia() throw() {}

//***********************************

template <typename T>
ListaDoble<T>::ListaNoMemoria::ListaNoMemoria() throw(){}

//***********************************

template <typename T>
ListaDoble<T>::ListaIndice::ListaIndice() throw(){}

//***********************************

template <typename T>
const char *ListaDoble<T>::ListaVacia::what() const throw()
{
    return "La Lista se encuentra vac\241a.";
}

//***********************************

template <typename T>
const char *ListaDoble<T>::ListaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}

//***********************************

template <typename T>
const char *ListaDoble<T>::ListaIndice::what() const throw()
{
    return "Indice fuera de rango.";
}
