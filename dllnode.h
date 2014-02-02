#ifndef DLLNODE_H
#define DLLNODE_H

#include "object.h"
/*
* Esta clase sirve para representar un nodo de listas doblemente enlazadas   *
* Como lo dice el nombre de la clase:                                        *
* Doble                                                                      *
* Linked                                                                     *
* List                                                                       *
* Node                                                                       *
* Los miembros de la clase sirven para las diferentes partes del nodo        *
* [   PREV    ]             Es el puntero al nodo anterior                   *
* [   DATA    ]             Es el puntero al Objeto que contiene los datos   *
* [   NEXT    ]             Es el puntero al nodo siguiente                  *
* ----------------------------------------------------------------------------
* NOTAS:                                                                     *
* En esta implementación se coloca un método print, que lo único que hará    *
* es llamar al método print de data.                                         *
* En esta implementación el destructor de esta clase destruirá cualquier     *
* cosa que esté enlazada con el nodo, de la misma manera que una cadena se   *
* suelta al cortar un eslabón.                                               *
*/

class DLLNode
{
    Object* data;
    DLLNode* prev;
    DLLNode* next;
  public:
    DLLNode();
    DLLNode(Object*);
    DLLNode(Object*, DLLNode*, DLLNode*);
    ~DLLNode();
    void print()const;
    DLLNode* getNext()const;
    DLLNode* getPrev()const;
    void setNext(DLLNode*);
    void setPrev(DLLNode*);
    Object* getData()const;
    void setData(Object*);
};

#endif
