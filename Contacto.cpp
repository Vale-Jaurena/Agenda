#include "Contacto.h"
#include <string>

using namespace std;

Contacto:: Contacto(){
    this->cumple= " ";
    this->mail= " ";
    this->nombre= " ";
    this->puesto= " ";
    this->notas= " ";
    this->direc= " ";
    this->organizacion= " ";
    this->tel= " ";
    visitas=0;
}
Contacto::Contacto(string  nombre,string apellido, string tel,string mail,string direc,string cumple,string organizacion,string puesto,string notas){
    this->cumple= cumple;
    this->apellido= apellido;
    this->mail= mail;
    this->nombre= nombre;
    this->puesto= puesto;
    this->notas= notas;
    this->direc= direc;
    this->organizacion= organizacion;
    this->tel= tel;
    this->visitas=0;
}

Contacto ::Contacto(const Contacto & Otro){
    this->cumple=Otro.cumple;
    this->mail= Otro.mail;
    this->nombre=Otro.nombre;
    this->puesto= Otro.puesto;
    this->notas= Otro.notas;
    this->direc= Otro.direc;
    this->organizacion= Otro.organizacion;
    this->tel=Otro.tel;
    this->visitas=Otro.visitas;
    this->redes= Otro.redes;
}
void Contacto :: Agregar_redes (string red){
    if (redes.Existe_E_List(red))
        cout<<"La red ya existe, no es posible agregarla"<<endl;
    else{
        redes.Agregar_Lista(red);
    }
}

int Contacto:: modif_visitas (){
    return visitas= visitas +1;
}

void Contacto::modif_redes(string Red_Vieja, string Red_Nueva){
    this->redes.Modificar(Red_Vieja,Red_Nueva);
}


void Contacto::modif_tel (string tel){
    this->tel=tel;
}

void Contacto::modif_cumple (string cumple){
    this->cumple=cumple;
}

void Contacto::modif_nombre (string nombre){
    this->nombre=nombre;
}

void Contacto::modif_apellido (string apellido){
    this->apellido=apellido;
}

void Contacto::modif_puesto (string puesto){
    this->puesto=puesto;
}

void Contacto::modif_organizacion (string organizacion){
    this->organizacion=organizacion;
}

void Contacto::modif_notas (string notas){
    this->notas=notas;
}

void Contacto::modif_mail (string mail){
    this->mail=mail;
}

void Contacto::modif_direc (string direc){
    this->direc=direc;
}
 string Contacto ::  Get_Cumple()const{
    return this->cumple;
}

string Contacto ::  Get_Direc()const {
    return this->direc;
}

 string Contacto ::  Get_Puesto()const {
    return this->puesto;
}

string Contacto ::  Get_Organizacion()const {
    return this->organizacion;
}

string Contacto ::Get_Nombre()const {
    return this->nombre;
}

string Contacto :: Get_Tel()const {
    return this->tel;
}

string Contacto ::Get_Notas()const {
    return this->notas;
}

string Contacto :: Get_Mail()const {
    return this->mail;
}

string Contacto :: Get_Apellido () const{
    return this->apellido;
}

void Contacto :: Get_Redes() const{
    int i;
    for (i=0; i<redes.Longitud(); i++){
       if (!redes.Vacia())
        cout << "La red social es: "<<redes.getElemento(i)<< endl;
    };
}

bool Contacto:: existe_nom (string nombre_b) const{
    if (nombre != nombre_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_tel (string tel_b) const{
    if (tel != tel_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_mail (string mail_b) const{
    if (mail != mail_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_direc (string direc_b) const{
    if (direc != direc_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_cumple (string cumple_b) const{
    if (cumple != cumple_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_organizacion (string organizacion_b) const{
    if (organizacion != organizacion_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_puesto (string puesto_b) const{
    if (puesto != puesto_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_notas (string notas_b) const{
    if (notas != notas_b){
        return false;
    }
    else
        return true;
}

bool Contacto :: existe_apellido(string apellido_b) const{
    if (apellido != apellido_b){
        return false;
    }
    else
        return true;
}

bool Contacto:: existe_redes (string red_b) const{
    if (not redes.Existe_E_List(red_b)){
        return false;
    }
    else
        return true;
}

bool Contacto::Visita()const{
    if (visitas != 0)
        return true;
    else
        return false;
}

bool Contacto::operator < (const Contacto & otro) const{
    if (this->nombre != otro.Get_Nombre())
        return this->nombre < otro.Get_Nombre();
    if (this->apellido != otro.Get_Apellido())
        return this->apellido < otro.Get_Apellido();
    return this->tel < otro.Get_Tel();
}

bool Contacto ::operator > (const Contacto & otro) const{
    if (this->nombre != otro.Get_Nombre())
        return this->nombre > otro.Get_Nombre();
    if (this->apellido != otro.Get_Apellido())
        return this->apellido > otro.Get_Apellido();
    return this->tel > otro.Get_Tel();
}

bool Contacto::operator == (const Contacto & otro) const{
    return (this->nombre == otro.Get_Nombre());
}

void Contacto:: Get_Contacto() const{
    cout<<"Nombre: "<<Get_Nombre()<<endl;
    cout<<"Apellido: "<<Get_Apellido()<<endl;
    cout<<"Telefono: "<<Get_Tel()<<endl;
    cout<<"Mail: "<<Get_Mail()<<endl;
    cout<<"Direccion: "<<Get_Direc()<<endl;
    cout<<"Cumpleaños: "<<Get_Cumple()<<endl;
    cout<<"Organizacion: "<<Get_Organizacion()<<endl;
    cout<<"Puesto: "<<Get_Puesto()<<endl;
    cout<<"Notas: "<<Get_Notas()<<endl;
    Get_Redes();
}
