#include <iostream>

void ListaDoble::AgregarEnPos(T valor, int pos)
{
    if(pos < 0 || pos > numElem) throw "s";

    if(pos == 0) AgregarAlInicio(valor);
    else if (pos == numElem) AgregarAlFinal(valor);
    else{
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
        }catch(){}
    }
}

void ListaDoble::EliminarDelFinal()
{
    if (EstaVacia() ) throw "Valor fuera de rango.";

    ultimo = ultimo->anterior;
    delete primero;
    primero = nullptr;
}

bool ListaDoble::EstaVacia()
{
    if (numElem == 0){
        return true;
    }
    return false;
}
