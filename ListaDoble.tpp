#include <iostream>

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
        // EXCEPCION
        std::cerr << "t ekibokastes prro :v";
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
        // EXCEPCION
        std::cerr << "t ekibokastes prro :v";
    }
}

template <typename T>
void ListaDoble<T>::AgregarEnPos(T valor, int pos)
{
    if(pos < 0 || pos >= numElem) throw "s";

    if(pos == 0){
        AgregarAlInicio(valor);

    }else if (pos == numElem){
        AgregarAlFinal(valor);

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
                visitado = primero;
            }
        }

        try{
            Elemento *nuevo = new Elemento(valor, visitado->anterior, visitado);
            visitado->anterior->siguiente = nuevo;
            visitado->anterior = nuevo;
            numElem++;
        }catch(const std::bad_alloc&){

        }
    }
}

template <typename T>
void ListaDoble<T>::EliminarInicio()
{
    if(EstaVacia()){
        // throw
    }

    Elemento *porBorrar = primero;

    if(numElem == 1){
        primero = nullptr;
        ultimo = nullptr;

    }else{
        primero->siguiente->anterior = nullptr;
        primero = primero->siguiente;
        //porBorrar->siguiente = nullptr;
    }

    delete porBorrar;
    --numElem;
}

template <typename T>
void ListaDoble<T>::EliminarFinal()
{
    if (EstaVacia() ) throw "Valor fuera de rango.";

    ultimo = ultimo->anterior;
    delete primero;
    primero = nullptr;
}

template <typename T>
void ListaDoble<T>::EliminarEnPos(int pos)
{

}

template <typename T>
bool ListaDoble<T>::BuscarValor(T valor) const
{

}

template <typename T>
int ListaDoble<T>::BuscarPosicion(T valor) const
{

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

}

template <typename T>
void ListaDoble<T>::Imprimir() const
{

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

