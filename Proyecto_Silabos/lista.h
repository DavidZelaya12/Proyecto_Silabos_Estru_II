#ifndef LISTA_H
#define LISTA_H
#include <nodo.h>
#include <iostream>

using std::cout;
using std::string;

template<typename tipo>
class lista{
    friend class cframe;
private:
    nodo<tipo> *UltPtr;
    int Cant;
public:
    lista();
    ~lista();
    nodo<tipo> *PrimPtr;
    void Limpiar();
    void InsertarInicio(const tipo &);
    void InsertarFinal(const tipo &);
    void InsertarPosicion(const tipo &,int);
    bool EliminarInicio(tipo &);
    bool EliminarFinal(tipo &);
    bool EliminarPosicion(tipo &,int);
    bool Vacia()const;
};

template<typename tipo>
lista<tipo>::lista() : PrimPtr(0), UltPtr(0), Cant(0)
{}

template<typename tipo>
lista<tipo>::~lista()
{
    Limpiar();
}

template<typename tipo>
void lista<tipo>::Limpiar()
{
    if( !Vacia() ){
        cout<<"Limpiando memoria: \n";
        nodo<tipo> *ActPtr = PrimPtr;
        nodo<tipo> *TempPtr;
        for( ; ActPtr!=0; Cant--){
            TempPtr = ActPtr;
            cout<<TempPtr->Dato<<"\t";
            ActPtr = ActPtr->SigPtr;
            delete TempPtr;
        }
    }
}

template<typename tipo>
void lista<tipo>::InsertarInicio(const tipo &Dato)//ec
{
    nodo<tipo> *NuevoPtr = new nodo<tipo> (Dato);
    if(Vacia()){
        PrimPtr = UltPtr = NuevoPtr;
    }else{
        NuevoPtr->SigPtr = PrimPtr;
        PrimPtr = NuevoPtr;
    }
    Cant++;
}

template<typename tipo>
void lista<tipo>::InsertarFinal(const tipo &Dato)
{
    nodo<tipo> *NuevoPtr = new nodo<tipo> (Dato);
    if(Vacia()){
        PrimPtr = UltPtr = NuevoPtr;
    }else{
        UltPtr->SigPtr = NuevoPtr;
        UltPtr = NuevoPtr;
    }
    Cant++;
}

template<typename tipo>
bool lista<tipo>::EliminarInicio(tipo &Dato)
{
    if( !Vacia() ){
        nodo<tipo> *ElimPtr = PrimPtr;
        PrimPtr = PrimPtr->SigPtr;
        Dato = ElimPtr->Dato;
        delete ElimPtr;
        Cant--;
        return true;
    }else{
        return false;
    }
}

template<typename tipo>
bool lista<tipo>::Vacia()const
{
    return PrimPtr==0;
}



#endif // LISTA_H
