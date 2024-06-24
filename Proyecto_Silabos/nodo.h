#ifndef NODO_H
#define NODO_H

template<typename tipo> class lista;
template<typename tipo>
class nodo{
    friend class lista<tipo>;
    friend class cframe;
private:
    //nodo<tipo> *AntPtr;
    tipo Dato;
    nodo<tipo> *SigPtr;
public:
    nodo(const tipo &);
    tipo getDato()const;
};

template<typename tipo>
nodo<tipo>::nodo(const tipo &Dato) : Dato(Dato), SigPtr(0)
{}

template<typename tipo>
tipo nodo<tipo>::getDato() const
{
    return Dato;
}


#endif // NODO_H
