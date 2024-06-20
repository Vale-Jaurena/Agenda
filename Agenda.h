#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "Arbol_AVL.h"

class Agenda {
public:
    Agenda();
    ~Agenda();
    void Agregar_Agenda ();
    void Eliminar_Contacto (const string & elemento);
    bool Busqueda_ag (const string & elemento) ;
    void Mostrar ();
    void Mostrar_Info_Nodo(const string & elemento);
    void Contactos_Visitados();
private:
    Arbol_AVL<Contacto> agenda;
};


#endif // AGENDA_H_INCLUDED
