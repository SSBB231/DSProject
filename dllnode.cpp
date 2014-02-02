#include "dllnode.h"
#include "object.h"
#include <iostream>
using std::cout;
using std::endl;
// Definición de los métodos de la clase DLLNode

// Constructor por Defecto de la Clase. Raramente Usado
DLLNode::DLLNode(){
    next = prev = NULL;
    data = NULL;
}
// Constructor especial de la Clase. Este es el más utilizado
DLLNode::DLLNode(Object* aData){
    data = aData;
}
// Constructor especial de la Clase. Raramente Usado
DLLNode::DLLNode(Object* aData, DLLNode* aPrev, DLLNode* aNext){
    data = aData;
    next = aNext;
    prev = aPrev;
}
/*
* Destructor Súper Poderoso de la Clase                                       *
* Este destructor liberará la memoria que esté ocupando la data a la que      *
* apunte el nodo, de la misma manera, liberará al nodo siguiente, en el caso  *
* de que hubiera alguno. De esta manera se libera todo lo que tenga el nodo y *
* sus siguientes.                                                             *
* Este destructor es muy útil, sin embargo hay que tener cuidado al querer    *
* sólo liberar un nodo, pues este deberá estar suelto.                        *
*/
DLLNode::~DLLNode(){
    if (data)
        delete data;
    if (next)
        delete next;
}
// Impresión del Nodo, sólo manda a imprimir el contenido de la data.
void DLLNode::print()const{
    data->print();
}
// Método Accesor de Next
DLLNode* DLLNode::getNext()const{
    return next;
}
// Método Accesor de Prev
DLLNode* DLLNode::getPrev()const{
    return prev;
}
// Método Mutador de Next
void DLLNode::setNext(DLLNode* aNext){
    next = aNext;
}
// Método Mutador de Prev
void DLLNode::setPrev(DLLNode* aPrev){
    prev = aPrev;
}
// Método Accesor de Data
Object* DLLNode::getData()const{
    return data;
}
// Método Mutador de Data
void DLLNode::setData(Object* aData){
    data = aData;
}

