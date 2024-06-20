#include "Lista.h"
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
Lista<T>:: Lista(){
    Inicial=NULL;
    pos=0;
}

template <typename T>
Lista <T> :: ~Lista(){
   // vaciar();
}

template<typename T>
const T & Lista<T> :: getElemento(int & Busco) const{
    int i=0;
    Nodo*aux= Inicial;
    while (aux != NULL and i<= pos){
        if (i==Busco){
            return aux->elemento;
        }
        else{
            i++;
            aux=aux->sig;
        }
    }
    return NULL;
}

//Agrega al inicio.
template <typename T>
void Lista<T>:: Agregar_Lista (const T & elemento){
    Nodo * nuevo= new Nodo();
    if (!Existe_E_List(elemento)){
        nuevo->elemento = elemento;
        nuevo->sig= Inicial;
        Inicial= nuevo;
        pos++;
    }
}
template <typename T>
void Lista<T>:: Eliminar_Lista(const T & elemento){
    if (Inicial != NULL){
        Nodo * aux_borrar = Inicial;
        Nodo * ant = NULL;
        while (aux_borrar != NULL and aux_borrar->elemento!= elemento){
            ant = aux_borrar;
            aux_borrar= aux_borrar->sig;
        }
        if (aux_borrar==NULL){
            cout<<"El elemento no existe"<<endl;
        }
        else{
            if (ant == NULL){
                Inicial= aux_borrar->sig;
                delete aux_borrar;
                pos--;
            }
            else {
               ant->sig=aux_borrar->sig;
                delete aux_borrar;
                pos--;
            }
        }
    }
}

template <typename T>
void Lista<T> :: vaciar(){
    Nodo * aux;
    while (Inicial != NULL) {
        aux = Inicial->sig;
        delete Inicial;
        Inicial = aux;
    }
    Inicial = NULL;
}

template <typename T>
bool Lista<T>:: Existe_E_List (const T & elemento) const{
    Nodo*aux=Inicial;
    while (aux != NULL and aux->elemento != elemento){
        aux = aux->sig;
    }
    if (aux == NULL)
        return false;
    if (aux->elemento == elemento)
        return true;
}

template<typename T>
void Lista<T>:: Modificar (const T & elemento, const T & OtroElemento){
    if ( elemento != OtroElemento){
        if (Existe_E_List(elemento)and not Existe_E_List(OtroElemento)){
            Eliminar_Lista(elemento);
            Agregar_Lista(OtroElemento);
        }
        else
            if (not Existe_E_List(OtroElemento))
                Agregar_Lista(OtroElemento);
    }
    else
        if (not Existe_E_List(elemento))
            Agregar_Lista(elemento);
}

template <typename T>
int Lista<T>:: Longitud () const {
    return pos;
}

template <typename T>
bool Lista<T>:: Vacia () const{
    if (Inicial != NULL)
        return false;
    else
        return true;
}

template class Lista<string>;
