#include <iostream>
#include "Arbol_AVL.h"
#include <string>

using namespace std;

template<typename T>
Arbol_AVL<T>::Arbol_AVL() {
    inicial=NULL;
}

template<typename T>
Arbol_AVL<T>:: ~Arbol_AVL(){
   // vaciar(inicial);
}

template<typename T>
bool Arbol_AVL<T>::Es_Hoja() const{
    if (inicial->der == NULL and inicial->izq == NULL)
        return true;
    else
        return false;
}

template<typename T>
int Arbol_AVL<T>::Actualizar_Alt(Nodo_Arb * arbol) {
    if ( arbol != NULL){
        if (Es_Hoja())
            return 1;
        else{
            int alt_der, alt_izq;
            if (arbol->der == NULL)
                alt_der=0;
            else
                alt_der= arbol->der->alt;
            if (arbol->izq != NULL)
                alt_izq= arbol->izq->alt;
            else alt_izq=0;
            return 1+max (alt_der, alt_izq);
        }
    }
    return 0;
}

template<typename T>
bool Arbol_AVL<T>:: Busqueda_E_Arbol(const T & datas,Nodo_Arb * arbol) const{
    if (arbol != NULL){
        if (arbol->elemento == datas)
            return true;
        else{
            if (datas > arbol->elemento)
                return Busqueda_E_Arbol(datas,arbol->der);
            else
               return  Busqueda_E_Arbol(datas,arbol->izq);
        }
    }
    return false;
}

template<typename T>
typename Arbol_AVL<T>::Nodo_Arb * Arbol_AVL<T>::Rotacion_Izq(Nodo_Arb * a){

    Nodo_Arb * b = a->der;
    Nodo_Arb * aux= b->izq;

    b->izq= a;
    a->der= aux;

    if (a!=NULL)
        a->alt=Actualizar_Alt(a);
    if (b!=NULL)
        b->alt=Actualizar_Alt(b);

    return b;
}

template<typename T>
typename Arbol_AVL<T>::Nodo_Arb* Arbol_AVL<T>::Rotacion_Der(Nodo_Arb* b){
   Nodo_Arb * a = b->izq;
   Nodo_Arb * aux=  a->der;

   a->der= b;
   b->izq= aux;

   if (b!=NULL)
   b->alt=Actualizar_Alt(b);
   if (a!=NULL)
   a->alt=Actualizar_Alt(a);
   return a;
}

template<typename T>
int Arbol_AVL<T>:: Calcular_Balance(Nodo_Arb * arbol) {
    if (arbol == NULL)
        return 0;
    else{
        int izq=0;
        if (arbol->izq !=NULL)
            izq = arbol->izq->alt;
        int der=0;
        if (arbol->der !=NULL)
            der = arbol->der->alt;
        return izq-der;
    }
}

template<typename T>
typename Arbol_AVL<T>::Nodo_Arb*Arbol_AVL<T>:: Agregar_Arb(const T & data, Nodo_Arb* arbol){
    if ( arbol ==NULL) {
        return new Nodo_Arb(data);
    }
    else{
        if (data < arbol->elemento)
            arbol->izq= Agregar_Arb(data, arbol->izq);
        else
            if (data > arbol->elemento)
                arbol->der= Agregar_Arb(data,arbol->der);
            else
                return arbol;
    }
    if (arbol != NULL){
        arbol->alt= Actualizar_Alt(arbol);
        int Balance=Calcular_Balance(arbol);
        if (Balance > 1 and data < arbol->izq->elemento)
            return Rotacion_Der(arbol);
        if (Balance < -1 and data > arbol->der->elemento)
            return Rotacion_Izq(arbol);
        if (Balance > 1 and data > arbol->izq->elemento){
            arbol->izq=Rotacion_Izq(arbol->izq);
            return Rotacion_Der(arbol);
        }
        if (Balance < -1 and data < arbol->der->elemento){
            arbol->der=Rotacion_Der(arbol->der);
            return Rotacion_Izq(arbol);
        }
    }
    return arbol;
}

//va a encontrar el menor de todo el arbol
template<typename T>
typename Arbol_AVL<T>::Nodo_Arb*Arbol_AVL<T>:: menor(Nodo_Arb * arbol) {
    if (arbol==NULL)
        return NULL;
    else{
        Nodo_Arb* actual = arbol;
        while (actual->izq != NULL){
            actual=actual->izq;
        }
        return actual;
    }
}

template<typename T>
typename Arbol_AVL<T>::Nodo_Arb*Arbol_AVL<T>:: Eliminar (Nodo_Arb*inicial,const T & data){
    if (inicial == NULL)
        return inicial;
    if (data < inicial->elemento)
        inicial->izq = Eliminar(inicial->izq, data);
     else
        if (data > inicial->elemento)
            inicial->der = Eliminar(inicial->der, data);
        else {
        // Nodo encontrado, realizar la eliminación
            if (inicial->izq == NULL or inicial->der == NULL) {
                Nodo_Arb* aux = inicial->izq ? inicial->izq : inicial->der;
                if (aux == NULL){
                    delete inicial;
                    inicial=NULL;
                }
                else{
                    inicial->elemento=aux->elemento;
                    inicial->der=aux->der;
                    inicial->izq=aux->izq;
                    delete aux;
                }
            }
            else {
                Nodo_Arb * aux= menor(inicial->der);
                inicial->elemento = aux->elemento;
                inicial->der = Eliminar(inicial->der, aux->elemento);
            }
        }
    // Si el árbol tiene un solo nodo
    if (inicial == NULL)
        return inicial;
    else{
        inicial->alt =Actualizar_Alt(inicial);
        int balance = Calcular_Balance(inicial);
        if (balance > 1 and Calcular_Balance(inicial->izq) >= 0)
            return Rotacion_Der(inicial);
        if (balance < -1 and Calcular_Balance(inicial->der) <= 0)
            return Rotacion_Izq(inicial);
        if (balance > 1 and Calcular_Balance(inicial->izq) < 0) {
            inicial->izq = Rotacion_Izq(inicial->izq);
            return Rotacion_Der(inicial);
        }
        if (balance < -1 and Calcular_Balance(inicial->der) > 0) {
            inicial->der = Rotacion_Der(inicial->der);
            return Rotacion_Izq(inicial);
        }
    }
    Mostrar_Arb();
        return inicial;
}

template <typename T>
void Arbol_AVL<T>:: getArb(Nodo_Arb * arbol){
    if (arbol != NULL){
        cout<<arbol->elemento.Get_Nombre()<<endl;
        getArb(arbol->der);
        getArb(arbol->izq);
    }
}

template < typename T>
void Arbol_AVL<T>:: getElemento(const T & data,Nodo_Arb * arbol){
    if (arbol!= NULL){
        if (data.Get_Nombre() != arbol->elemento.Get_Nombre()){
            getElemento(data,arbol->izq);
            getElemento(data,arbol->der);
        }
        else{
            cout <<arbol->elemento.Get_Nombre()<<endl;
            arbol->visita=true;
        }
    }
}

template <typename T>
void Arbol_AVL<T>:: Imprimir_Inorden(Nodo_Arb*arbol){
    if (arbol != NULL){
        Imprimir_Inorden(arbol->izq);
        if (arbol->visita)
            cout<< arbol->elemento.Get_Nombre()<<endl;
        Imprimir_Inorden(arbol->der);
    }
}

template <typename T>
void Arbol_AVL<T>:: vaciar(Nodo_Arb * arbol){
    if (arbol != NULL){
        vaciar(arbol->der);
        vaciar(arbol->izq);
        delete arbol;
    }
}
template <typename T>
void Arbol_AVL<T>:: Mostrar_Arb(){
    getArb(inicial);
}

template <typename T>
void Arbol_AVL<T>::Insertar_Elem(const T & data){
    inicial=Agregar_Arb(data,inicial);
}

template <typename T>
void Arbol_AVL<T>::Eliminar_Arbol(const T & data){
    inicial=Eliminar(inicial,data);
}

template <typename T>
bool Arbol_AVL<T>::Busqueda (const T & datas)const{
    bool aux= Busqueda_E_Arbol (datas, inicial);
    return aux;
}

template<typename T>
void Arbol_AVL<T>::Nodos_Visitados(){
    Imprimir_Inorden(inicial);
}

template<typename T>
void Arbol_AVL<T>::Nodo_Puntual(const T & data){
    getElemento(data,inicial);
}

template <typename T>
const T Arbol_AVL<T>:: Buscar_Nodo(const T & data, Nodo_Arb*arbol){
    if (arbol != NULL){
        if (data == arbol->elemento)
            return arbol->elemento;
        else{
            if( data < arbol->elemento)
                Buscar_Nodo(data,arbol->izq);
            else
                Buscar_Nodo(data,arbol->der);
        }
    }
}

template <typename T>
const T Arbol_AVL<T>:: Devolver_Elemento(const T &data){
    const T aux= Buscar_Nodo(data,inicial);
    return aux;
}

template class Arbol_AVL<Contacto>;
