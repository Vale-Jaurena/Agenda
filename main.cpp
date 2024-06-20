//#include <iostream>
#include "Contacto.h"
#include "Agenda.h"
#include "Arbol_AVL.h"
#include <cstdlib>
//using namespace std;



int main()
{
    int opcion;
    string aux;
    bool repetir= true;
    Agenda agen;

    do{
        system("cls");
        cout<<"1.Agregar un Contacto."<<endl;
        cout<<"2.Eliminar un Contacto."<<endl;
        cout<<"3.Buscar un Contacto."<<endl;
        cout<<"4.Mostrar toda la agenda."<<endl;
        cout<<"5.Ver informacion de un contacto."<<endl;
        cout<<"6.Imprimir contactos visitados."<<endl;
        cout<<"0. Desea finalizar:"<<endl;
        cout<<"¿Que opcion desea elegir?"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                agen.Agregar_Agenda();
                system("pause>nul"); // Pausa
                break;
            case 2:
                cout<<"Ingrese el contacto a eliminar, el nombre:"<<endl;
                cin>>aux;
                agen.Eliminar_Contacto(aux);
                system("pause>nul"); // Pausa
                break;
            case 3:
                cout<<"Ingrese el contacto a buscar, el nombre:"<<endl;
                cin>>aux;
                if (agen.Busqueda_ag(aux))
                    cout<<"El contacto existe."<<endl;
                else
                    cout<<"El contacto no existe"<<endl;
                system("pause>nul"); // Pausa
                break;
            case 4:
                agen.Mostrar();
                system("pause>nul"); // Pausa
                break;
            case 5:
                cout<<"Ingrese el nombre del contacto:"<<endl;
                cin>>aux;
                agen.Mostrar_Info_Nodo(aux);
                system("pause>nul"); // Pausa
                break;
            case 6:
                agen.Contactos_Visitados();
                system("pause>nul"); // Pausa
                break;
            case 0:
                repetir = false;
                system("pause>nul"); // Pausa
                break;
        }
    }while(repetir);



    return 0;
}
