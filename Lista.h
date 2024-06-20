#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template< typename T >
class Lista {
public:
    Lista();
    ~Lista();
    void Agregar_Lista(const T & elemento);
    void Eliminar_Lista(const T & elemento);
    const T & getElemento(int & Busco) const;
    void Modificar(const T & elemento, const T & OtroElemento);
    bool Existe_E_List (const T & elemento) const;
    int Longitud () const;
    bool Vacia () const;
private:
    struct Nodo{
        Nodo * sig;
        T elemento;
    };
    Nodo * Inicial;
    void vaciar();
    int pos;
};

#endif // LISTA_H_INCLUDED
