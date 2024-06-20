#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED
#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;
class Contacto{
private:
    string nombre;
    string apellido;
    string tel;
    string mail;
    string direc;
    string cumple;
    string organizacion;
    string puesto;
    string notas;
    Lista <string> redes;
    int visitas;
public:
    Contacto ();
    Contacto(string  nombre, string apellido, string tel,string mail,string direc,string cumple,string organizacion,string puesto,string notas);
    Contacto (const Contacto & Otro);
    void modif_nombre (string nombre);
    void modif_apellido (string apellido);
    void modif_direc (string direc);
    void modif_mail(string mail);
    void modif_tel (string tel);
    void modif_cumple (string cumple);
    void modif_organizacion (string organizacion);
    void modif_puesto (string puesto);
    void modif_notas (string notas);
    void modif_redes (string Red_Vieja,string Red_Nueva);
    bool existe_nom (string nombre_b) const;
    bool existe_apellido (string apellido_b) const;
    bool existe_tel (string tel_b) const;
    bool existe_mail (string mail_b) const;
    bool existe_direc (string direc_b) const;
    bool existe_cumple (string cumple_b) const;
    bool existe_organizacion (string organizacion_b) const;
    bool existe_puesto (string puesto_b) const;
    bool existe_notas (string notas_b) const;
    bool existe_redes (string red_b) const;
    bool Visita () const;
    bool operator < (const Contacto & otro) const;
    bool operator > (const Contacto & otro) const;
    bool operator == (const Contacto & otro) const;
    string Get_Direc()const;
    string Get_Mail()const;
    string Get_Nombre()const;
    string Get_Apellido () const;
    string Get_Puesto()const;
    string Get_Cumple()const;
    string Get_Tel()const;
    string Get_Organizacion()const;
    string Get_Notas()const;
    void Get_Contacto() const;
    void Get_Redes()const;
    void Agregar_redes (string red);
    int modif_visitas ();
};
#endif // CONTACTO_H_INCLUDED
