#ifndef ARBOL_AVL_H_INCLUDED
#define ARBOL_AVL_H_INCLUDED
#include "Contacto.h"

using namespace std;

template <typename T>
class Arbol_AVL {
public:
    Arbol_AVL();
    ~Arbol_AVL();
    void Insertar_Elem(const T & data);
    void Eliminar_Arbol(const T & data);
    void Nodos_Visitados();
    void Mostrar_Arb();
    void Nodo_Puntual(const T & data);
    const T Devolver_Elemento(const T & data);
    bool Busqueda(const T & datas) const;

private:
    struct Nodo_Arb{
        T elemento;
        Nodo_Arb* izq;
        Nodo_Arb* der;
        int alt;
        bool visita;
        Nodo_Arb(const T & valor): elemento(valor), der(NULL), izq(NULL), alt(1), visita(false) {}
    };
    Nodo_Arb * inicial;

    void vaciar(Nodo_Arb*Arbol);
    void getArb(Nodo_Arb * Arbol);
    void getElemento(const T & data, Nodo_Arb* Arbol);
    void Imprimir_Inorden(Nodo_Arb*Arbol);
    bool Es_Hoja() const;
    bool Busqueda_E_Arbol(const T & datas, Nodo_Arb * Arbol) const;//Creo que deberia ir en la parte plubica
    Nodo_Arb* Rotacion_Izq(Nodo_Arb * b);
    Nodo_Arb * Rotacion_Der(Nodo_Arb * a);
    Nodo_Arb* Agregar_Arb(const T & data,Nodo_Arb* Arbol);
    Nodo_Arb* Eliminar(Nodo_Arb * inicial, const T & data);
    Nodo_Arb * menor (Nodo_Arb * Arbol);
    int Actualizar_Alt(Nodo_Arb * Arbol);
    int Calcular_Balance(Nodo_Arb * Arbol);
    const T Buscar_Nodo (const T & data, Nodo_Arb * Arbol);
};

#endif //
