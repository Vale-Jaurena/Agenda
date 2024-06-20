#include <iostream>
#include <cassert>
#include "Agenda.h"

using namespace std;

Agenda:: Agenda (){
}

Agenda::~Agenda(){
}
void Agenda:: Agregar_Agenda(){
    string n,a,t,m,d,c,o,p,nota,r,aux;
    cout<<"Ingrese el Nombre:"<<endl;
    cin>>n;
    cout <<"Ingrese el Apellido:"<<endl;
    cin>>a;
    cout<<"Ingrese el Telefono:"<<endl;
    cin>>t;
    cout<<"Ingrese el mail:"<<endl;
    cin>>m;
    cout<<"Ingrese la direccion: "<<endl;
    cin>>d;
    cout<<"Ingrese el cumpleaños:"<<endl;
    cin>>c;
    cout<<"Ingrese la organizacion: "<<endl;
    cin>>o;
    cout<<"Ingrese el puesto: "<<endl;
    cin>>p;
    cout<<"Ingrese notas adicionales: "<<endl;
    cin>>nota;
    cout<<" Para ingresar mas de una red ingrese 0 sino agregue la red"<<endl;
    cin>>aux;
    Contacto nuevo;
    nuevo.modif_nombre(n);
    nuevo.modif_apellido(a);
    nuevo.modif_tel(t);
    nuevo.modif_mail(m);
    nuevo.modif_direc(d);
    nuevo.modif_cumple(c);
    nuevo.modif_organizacion(o);
    nuevo.modif_puesto(p);
    nuevo.modif_notas(nota);
    if (aux=="0"){
        while (aux == "0" ){
            if (aux=="0"){
                cout<<"ingrese la red"<<endl;
                cin>>r;
                nuevo.Agregar_redes(r);
                cout<<"Desea ingresar otra red? Ingrese 0 para si y 2 para no"<<endl;
                cin>>aux;
            }
        }
    }
    else
        nuevo.modif_redes(r,r);
    this->agenda.Insertar_Elem(nuevo);

}

void Agenda::Eliminar_Contacto (const string & elemento){
    Contacto nuevo,aux;
    nuevo.modif_nombre(elemento);
    aux=agenda.Devolver_Elemento(nuevo);
    cout<<"Chequear si nuevo tiene el nombre"<<aux.Get_Nombre()<<endl;
    this->agenda.Eliminar_Arbol(aux);
    cout<<"fin eliminar";
}

bool Agenda:: Busqueda_ag (const string & elemento) {
    Contacto nuevo;
    nuevo.modif_nombre(elemento);
    return agenda.Busqueda(nuevo);
}


void Agenda::Mostrar(){
    agenda.Mostrar_Arb();
}

void Agenda:: Mostrar_Info_Nodo(const string & elemento){
    Contacto nuevo;
    nuevo.modif_nombre(elemento);
    Contacto aux ;
    aux=agenda.Devolver_Elemento(nuevo);
    if (aux == nuevo){
        aux.Get_Contacto();
        }
    else
        cout<<"El contacto no existe"<<endl;
}

void Agenda:: Contactos_Visitados(){
    agenda.Nodos_Visitados();
}
